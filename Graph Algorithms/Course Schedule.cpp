/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1679/
* @refer: https://www.youtube.com/watch?v=ddTC4Zovtbc
* @TC: O(V + E)
* @desc: dfs2(): Topological sort
    # dfs(): If cycle, then ans doesn't exist
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
 
#define INF 1e15

const int N = 1e5+5;
vector<int> graph[N];
vector<bool> vis(N, 0);
vector<bool> recurStack(N, 0);
vector<int> parent(N, -1);
vector<int> topSort;
 
// Checking for cycle
bool dfs(int u){
    vis[u] = true;
    recurStack[u] = true;
    for(int v: graph[u]){
        if(vis[v]){
            if(recurStack[v]){
                return true;
            }
            continue;
        }
 
        if(dfs(v))
            return true;
    }
    recurStack[u] = false;
    return false;
}

// Topological Sort
void dfs2(int u){
    vis[u] = true;
    for(int v: graph[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
    topSort.pb(u);
}

int solve(){
    int n, m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    bool isCycle = false;
    for(int u = 1; u <= n; u++){
        if(!vis[u] && dfs(u)){
            isCycle = true;
            break;
        }   
    }
 
    if(!isCycle){
        for(int u = 1; u <= n; u++) vis[u] = 0;
        for(int u = 1; u <= n; u++){
            if(!vis[u]){
                dfs2(u);
            }   
        }
        reverse(topSort.begin(), topSort.end());
        _print(topSort);
    }
    else{
        print("IMPOSSIBLE");
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