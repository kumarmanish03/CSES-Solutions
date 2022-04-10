/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1648
* @logic: Segment Trees
*
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
#define fs  first
#define sc  second
#define pb  push_back
#define int long long

const int N = 2e5+1;
int segTree[4 * N];

// TC: O(n)
int construct(vector<int> &arr, int node, int sl, int sr){
    if(sl == sr){
        segTree[node] = arr[sl];
        return segTree[node];
    }

    int mid = sl + (sr - sl) / 2;
    segTree[node] = construct(arr, 2*mid+1, sl, mid) + construct(arr, 2*mid+2, mid+1, sr);
    return segTree[node];
}

// TC: O(logn)
int getSum(vector<int> &arr, int node, int sl, int sr, int l, int r){
    // Total Overlap
    if(l <= sl && sr <= r)
        return segTree[node];
    // No Overlap
    if(sl > r || sr < l)
        return 0;

    // Partial Overlap
    int mid = sl + (sr - sl) / 2;
    return getSum(arr, 2*mid+1, sl, mid, l, r) + getSum(arr, 2*mid+2, mid+1, sr, l, r);
}

// TC: O(logn)
void update(vector<int> &arr, int node, int sl, int sr, int pos, int diff){
    if(pos < sl || sr < pos)
        return;

    segTree[node] += diff;
    if(sl != sr){
        int mid = sl + (sr - sl) / 2;
        update(arr, 2*mid+1, sl, mid, pos, diff);
        update(arr, 2*mid+2, mid+1, sr, pos, diff);
    }
}

int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    construct(v, 0, 0, n-1);
    int type;
    while(q--){
        cin >> type;
        if(type == 1){
            int k, u;
            cin >> k >> u;
            int diff = u - v[k-1];
            v[k-1] = u;
            update(v, 0, 0, n-1, k-1, diff);
        }
        else{
            int a, b;
            cin >> a >> b;
            int sum = getSum(v, 0, 0, n-1, a-1, b-1);
            print(sum);
        }
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin>>t;
    for(int i = 0; i < t; i++)
        solve();
}
