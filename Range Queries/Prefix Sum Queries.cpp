/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2166
* @refer: https://usaco.guide/problems/cses-2166-prefix-sum-queries/solution
* @desc: see above article to understand
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
// {sum, max prefix sum}
pair<int, int> segTree[4*N];
int n;

pair<int, int> combine(pair<int, int> p1, pair<int, int> p2){
    return {p1.fs + p2.fs, max(p1.sc, p1.fs + p2.sc)};
}

void update(int pos, int val, int node = 0, int sl = 0, int sr = n-1){
    if(pos < sl || sr < pos)
        return;

    if(sl == sr){
        segTree[node] = {val, max(val, 0LL)};
    }
    else{
        int mid = (sl + sr) / 2;
        update(pos, val, 2*mid+1, sl, mid);
        update(pos, val, 2*mid+2, mid+1, sr);
        segTree[node] = combine(segTree[2*mid+1], segTree[2*mid+2]);
    }
}

pair<int, int> find(int l, int r, int node = 0, int sl = 0, int sr = n-1){
    if(r < sl || sr < l){
        return {0LL, 0LL};
    }

    if(l <= sl && sr <= r){
        return segTree[node];
    }

    int mid = (sl + sr) / 2;
    return combine(find(l, r, 2*mid+1, sl, mid), find(l, r, 2*mid+2, mid+1, sr));
}

int solve(){
    int q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        update(i, v[i]);
    }
    
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k, u;
            cin >> k >> u;
            update(k-1, u);
        }
        else{
            int a, b;
            cin >> a >> b;
            int mx = find(a-1, b-1).second;
            print(mx);
        }
    }
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}