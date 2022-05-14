/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1674/
* @desc: Tree with dp, easy
* @TC: O(n)
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

const int n = 2e5+5;
// dp[i] : stores total nodes in i subtree
int dp[n];

int count(int u, vector<vector<int>>&adj){
    if(adj[u].size() == 0)
        return dp[u] = 1;

    if(dp[u] != -1)
        return dp[u];

    int cnt = 1;
    for(auto v: adj[u]){
        cnt += count(v, adj);
    }

    return dp[u] = cnt;
}

int solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    int x;
    for(int i = 0; i < n-1; i++){
        cin >> x;
        adj[x].push_back(i+2);
    }

    memset(dp, -1, sizeof(dp));
    count(1, adj);
    for(int i = 1; i <= n; i++){
        cout << dp[i] - 1 << " ";
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