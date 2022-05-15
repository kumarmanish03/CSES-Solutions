/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1131/
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

int diameter = 0;

// dfs calculate max depth from node u
int dfs(int u, int p, vector<vector<int>> &adj){

    int max1 = 0, max2 = 0;
    for(int v: adj[u]){
        if(v == p) continue;
        int cnt = dfs(v, u, adj);
        // Finding two maximums
        if(max2 < cnt){
            if(max1 < cnt){
                max2 = max1;
                max1 = cnt;
            }
            else{
                max2 = cnt;
            }
        }
    }

    diameter = max(diameter, max1 + max2);

    return 1 + max1;
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

    dfs(1, -1, adj);
    print(diameter);
    
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}