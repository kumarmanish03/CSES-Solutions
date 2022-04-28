/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1143/
* @logic: Complex Segment Tree
* @TC: O(m * logn * logn)
*
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define print_(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
#define fs  first
#define sc  second
#define pb  push_back
#define int long long

const int N = 2e5+1;
int segTree[4*N];

int construct(vector<int> &arr, int node, int sl, int sr){
    if(sl == sr){
        segTree[node] = arr[sl];
        return segTree[node];
    }

    int mid = sl + (sr - sl) / 2;
    segTree[node] = max(construct(arr, 2*mid+1, sl, mid), construct(arr, 2*mid+2, mid+1, sr));
    return segTree[node];
}

int getMax(int node, int sl, int sr, int l, int r){
    if(l <= sl && sr <= r)
        return segTree[node];

    if(sr < l || r < sl)
        return INT_MIN;

    int mid = sl + (sr - sl) / 2;
    return max(getMax(2*mid+1, sl, mid, l , r), getMax(2*mid+2, mid+1, sr, l, r));
}

void update(int node, int sl, int sr, int pos, int value){
    if(pos < sl || sr < pos)
        return;

    if(sl == sr){
        segTree[node] = value;
    }
    else{
        int mid = sl + (sr - sl) / 2;
        update(2*mid+1, sl, mid, pos, value);
        update(2*mid+2, mid+1, sr, pos, value);
        segTree[node] = max(segTree[2*mid+1], segTree[2*mid+2]);
    }
}

// O(logn*logn)
int query(int l, int r, int val, int n){

    while((r-l) > 1){
        int mid = (l + r) / 2;
        if(val <= getMax(0, 0, n-1, l, mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }

    if(val <= getMax(0, 0, n-1, l, l))
        return l;
    else if(val <= getMax(0, 0, n-1, r, r))
        return r;
    else
        return -1;
}

int solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    construct(v, 0, 0, n-1);

    int t;
    while(m--){
        cin >> t;
        int idx = query(0, n-1, t, n);
        if(idx != -1){
            v[idx] -= t;
            update(0, 0, n-1, idx, v[idx]);
        }
        cout << idx + 1 << " ";
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
