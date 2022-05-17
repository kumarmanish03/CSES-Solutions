/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1668/
* @TC: O(n + m)
* @desc: DFS, try to make alternate nodes in diff team, if not possible return false, else true
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
vector<bool> team(N, -1);

bool dfs(int u, int t){
    vis[u] = true;
    bool status = true;
    team[u] = t;
    for(int v: graph[u]){
        if(vis[v]){
            // child and parent in same team
            if(t == team[v]){
                return false;
            }
            continue;
        }

        status &= dfs(v, t^1);
    }

    return status;
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

    bool isAns = true;
    for(int u = 1; u <= n; u++){
        if(vis[u]) continue;
        isAns &= dfs(u, 0);
    }

    if(isAns){
        for(int u = 1; u <= n; u++){
            cout << team[u]+1 << " ";
        }
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