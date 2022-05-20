/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1678/
* @refer: https://www.youtube.com/watch?v=GLxfoaZlRqs&t=238s
* @desc: Detect cycle in directed graph
    # Instead of parent, here we have to maintain recursion stack
    # If node is vis & in recursion stack then cycle present
* @TC: O(V + E)
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
vector<int> graph[N];
vector<bool> vis(N, 0);
vector<bool> recurStack(N, 0);
vector<int> parent(N, -1);
int node = -1;
 
bool dfs(int u){
    vis[u] = true;
    recurStack[u] = true;
    for(int v: graph[u]){
        if(vis[v]){
            if(recurStack[v]){
                node = v;
                parent[v] = u;
                return true;
            }
            continue;
        }
 
        parent[v] = u;
        if(dfs(v))
            return true;
    }
    recurStack[u] = false;
    return false;
}
 
int solve(){
    int n, m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for(int u = 1; u <= n; u++){
        if(!vis[u] && dfs(u)){
            break;
        }   
    }
 
    if(node != -1){
        vector<int> path;
        int temp = node;
        while(1){
            path.pb(temp);
            temp = parent[temp];
            if(temp == node || node == -1){
                path.pb(temp);
                break;
            }
        }
        reverse(path.begin(), path.end());
        print(path.size());
        _print(path);
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