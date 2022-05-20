/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1668/
* @TC: O(n + m)
* @desc: 
    # Detect cycle in Undirected graph
    # Checking for loop and saving its node, also maintaining parents to track its paths 
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

#define INF 1e9

const int N = 1e5+5;
vector<int> graph[N];
vector<bool> vis(N, false);
vector<int> parent(N, -1);

int node = -1;
int isFind = false;
bool dfs(int u, int p){

    vis[u] = true;
    bool ans = false;
    for(int v: graph[u]){
        if(vis[v]){
            // checking for loop and saving the node
            if(v != p){
                // if we already find loop then ignore
                if(isFind)
                    continue;
                parent[v] = u;
                node = v;
                isFind = true;
                return true;
            }
            continue;
        }
        parent[v] = u;
        ans |= dfs(v, u);
    }

    return ans;
}


int solve(){
    int n, m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool ans = false;
    for(int u = 1; u <= n; u++){
        if(vis[u]) continue;
        ans |= dfs(u, 0);
    }

    if(ans){
        vector<int> path;
        // tracking back loop using parents array
        int temp = node;
        while(1){
            path.push_back(node);
            node = parent[node];
            if(node == temp)
                break;
        }
        path.push_back(temp);
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