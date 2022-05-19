/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1195/
* @refer: https://codeforces.com/blog/entry/79518
* @TC: O(V + ElogV)
* @desc: Dijkstra Algorithm Modified:
    # dijkstra(), cost[]: finds cost from 1 to all other nodes
    # dijkstra2(), cost2[]: finds cost from n to all other nodes
    # Now we will loop through each edge and find min of => cost[src] + cost2[des] + wt/2
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

const int N = 1e5+5;
vector<pair<int, int>> graph[N];
vector<pair<int, int>> graph2[N];
vector<vector<int>> edges;
vector<bool> processed(N, false);
vector<int> cost(N, INF);
vector<int> cost2(N, INF);
int n;

void dijkstra(){
    set<pair<int, int>> s;
    s.insert({0, 1});
    cost[1] = 0;

    while(!s.empty()){
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        if(processed[u]) continue;

        processed[u] = true;
        for(auto [v, wt]: graph[u]){
            if(cost[u] + wt < cost[v]){
                cost[v] = cost[u] + wt;
                s.insert({cost[v], v});
            }
        }
    }
}

void dijkstra2(){
    processed.assign(N, false);
    set<pair<int, int>> s;
    s.insert({0, n});
    cost2[n] = 0;

    while(!s.empty()){
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        if(processed[u]) continue;

        processed[u] = true;
        for(auto [v, wt]: graph2[u]){
            if(cost2[u] + wt < cost2[v]){
                cost2[v] = cost2[u] + wt;
                s.insert({cost2[v], v});
            }
        }
    }
}


int solve(){
    int m;
    cin >> n >> m;
    int a, b, wt;
    while(m--){ 
        cin >> a >> b >> wt;
        // Ignore self loops
        if(a == b) continue;

        graph[a].push_back({b, wt});
        graph2[b].push_back({a, wt});
        edges.push_back({a, b, wt});
    }

    dijkstra();
    dijkstra2();

    int ans = INF;
    for(auto edge: edges){
        int src = edge[0];
        int des = edge[1];
        int wt = edge[2];
        ans = min(ans, cost[src] + cost2[des] + wt/2);
    }

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