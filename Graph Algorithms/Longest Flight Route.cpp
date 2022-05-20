/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1680/
* @TC: O(V + E)
* @desc: DFS, height[u]: stores heights of node u respective to n
    # If height[u] can be increased then increase it and store child[u]=v
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
vector<int> height(N, -INF);
vector<int> child(N, -1);
int n;

int dfs(int u){
    vis[u] = true;

    if(u == n){
        return height[u] = 1;
    }

    for(int v: graph[u]){
        if(vis[v]){
            if(height[v] != -INF){
                if(height[u] < 1 + height[v]){
                    height[u] = 1 + height[v];
                    child[u] = v;
                }
            }
        }
        else{
            // print(u, "->", v);
            if(dfs(v) != -INF){
                if(height[u] < 1 + height[v]){
                    height[u] = 1 + height[v];
                    child[u] = v;
                }
            }
        }
    }

    return height[u];
}

int solve(){
    int m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1);
    
    if(vis[n]){
        // print(height[1]);
        // for(int i = 1; i<=n;i++)print(i, child[i]);
        vector<int> path;
        int node = 1;
        while(1){
            path.pb(node);
            node = child[node];
            if(node == n){
                path.pb(node);
                break;
            }
        }
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