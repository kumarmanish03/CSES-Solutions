/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1130/
* @desc: Tree with dp
* @TC: O(V + E^2) [passes 92% test cases]
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

const int N = 2e5+5;

vector<bool> vis(N, false);

int dp[N][2];

int dfs(int u, bool isMatched, vector<vector<int>> &adj){

    if(dp[u][isMatched] != -1)
        return dp[u][isMatched];

    vis[u] = true;
    int cnt = 0;
    if(isMatched){
        for(auto v: adj[u]){
            if(vis[v]) continue;
            cnt += dfs(v, false, adj);
        }
    }
    else{
        for(int v1: adj[u]){
            int temp = 0;
            for(int v2: adj[u]){
                if(vis[v2]) continue;
                if(v1 == v2){
                    temp += 1 + dfs(v2, true, adj);
                }
                else{
                    temp += dfs(v2, false, adj);
                }
            }
            cnt = max(cnt, temp);
        }
    }
    vis[u] = false;
    return dp[u][isMatched] = cnt;
}

int solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(dp, -1, sizeof(dp));
    print(max(dfs(1, false, adj), dfs(1, true, adj)));
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}