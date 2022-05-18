/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1672/
* @refer: https://www.youtube.com/watch?v=5MEZXOyaRmk
* @desc: 
    # Floyd Warshall Algorithm :
    # TC: O(N^3) [N: no. of vertices]
    # Work for -ve weights
    # Doesn't work for -ve weight cycles [for -ve weight cycles, shortest path is Not Defined]
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

#define INF 1e17

int solve(){
    int n, m, q;
    cin >> n >> m >> q;
    int graph[n+1][n+1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    int a, b, wt;
    while(m--){
        cin >> a >> b >> wt;
        // Since there are multiple edges b/w two nodes, so taking min wt edge
        graph[a][b] = min(graph[a][b], wt);
        graph[b][a] = min(graph[b][a], wt);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                // Use this condn for -ve weights 
                if(graph[i][k] == INF || graph[k][j] == INF)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    while(q--){
        cin >> a >> b;
        int distance = (graph[a][b] == INF) ? -1 : graph[a][b];
        print(distance);
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