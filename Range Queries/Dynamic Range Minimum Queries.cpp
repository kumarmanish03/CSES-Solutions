/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1649
* @logic: Segment Tree, notice the change in segment Tree
* @refer: https://cp-algorithms.com/data_structures/segment_tree.html
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
    segTree[node] = min(construct(arr, 2*mid+1, sl, mid), construct(arr, 2*mid+2, mid+1, sr));
    return segTree[node];
}

int getMin(int node, int sl, int sr, int l, int r){
    if(l <= sl && sr <= r)
        return segTree[node];

    if(sr < l || r < sl)
        return INT_MAX;

    int mid = sl + (sr - sl) / 2;
    return min(getMin(2*mid+1, sl, mid, l , r), getMin(2*mid+2, mid+1, sr, l, r));
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
        segTree[node] = min(segTree[2*mid+1], segTree[2*mid+2]);
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
            v[k-1] = u;
            update(0, 0, n-1, k-1, u);
        }
        else{
            int a, b;
            cin >> a >> b;
            int mn = getMin(0, 0, n-1, a-1, b-1);
            print(mn);
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
