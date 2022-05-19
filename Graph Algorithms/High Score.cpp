/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1673/
* @topic: Bellman Ford Algorithm
* @desc: We have to find path with Maximum cost so we can multiply wt with -1
    # so problem reduces to find minimum cost
    # Also, we can have -ve weight cycles[for that we have to print -1] so we use Bellman ford algo
    # Also, graph can have more than one connected components
    # and if -ve wt cycle present in a connected component and not reachable from source and destination, then we have to ignore it
    # This thing we made dfs(), dfs2()
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

#define INF 1e16

const int N = 2505;
vector<int> graph[N];
vector<int> graph2[N];
vector<vector<int>> edges;
// nodes reachable from node 1
vector<bool> vis(N, false);
// nodes reachable from node n
vector<bool> vis2(N, false);
vector<int> dis(N, INF);
int n, m;

void dfs(int u){
    vis[u] = true;
    for(auto v: graph[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

void dfs2(int u){
    vis2[u] = true;
    for(auto v: graph2[u]){
        if(vis2[v]) continue;
        dfs2(v);
    }
}

int bellman_ford(){
    dis[1] = 0;
    for(int k = 0; k < n; k++){
        for(auto edge: edges){
            int src = edge[0];
            int des = edge[1];
            int wt = edge[2];
            if(dis[src] != INF){
                if(dis[src] + wt < dis[des]){
                    dis[des] = dis[src] + wt;
                    // If node is relaxed at nth time also then we have -ve wt cycle
                    // Also if it is accesible from 1 and n too then shortest path is Not Defined, then return -1
                    if(k == n-1 && vis[des] && vis2[des]){
                        return -1;
                    }
                }
            }
        }
    }

    return -dis[n];
}


int solve(){
    cin >> n >> m;
    int a, b, wt;
    while(m--){
        cin >> a >> b >> wt;
        graph[a].push_back(b);
        graph2[b].push_back(a);
        edges.push_back({a, b, -wt});
    }

    dfs(1);
    dfs2(n);
    int ans = bellman_ford();
    print(ans);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}