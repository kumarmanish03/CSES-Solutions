/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1666/
* @desc: similar to find no. of connected components
* @TC: O(N + M)
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

const int N = 1e5+5;
vector<int> tree[N];
vector<int> vis(N, false);

void dfs(int u){
    vis[u] = true;
    for(auto v: tree[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int solve(){
    int n, m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> v;
    for(int u = 1; u <= n; u++){
        if(!vis[u]){
            dfs(u);
            v.push_back(u);
        }
    }

    print(v.size()-1);
    for(int i = 1; i < v.size(); i++){
        print(v[i-1], v[i]);
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