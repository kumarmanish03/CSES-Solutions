/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1202/
* @TC: O(ElogV)
* @desc: Dijkstra with DP
    # Dijkstra Modified: we will try to keep all required states for all nodes
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
const int mod = 1e9+7;
vector<pair<int, int>> graph[N];
vector<bool> vis(N, 0);
vector<int> cost(N, INF);
vector<int> mnFlight(N, INF);
vector<int> mxFlight(N, -INF);
vector<int> routes(N, 1);
int n;

void dijkstra(){
    // {cost, node}
    multiset<pair<int, int>> s;
    s.insert({0, 1});
    cost[1] = 0;
    mnFlight[1] = 0;
    mxFlight[1] = 0;
    routes[1] = 1;

    while(!s.empty()){
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        if(u == n){
            return;
        }

        if(vis[u]) continue;

        vis[u] = true;
        for(auto [v, wt]: graph[u]){
            if(cost[v] > cost[u] + wt){
                cost[v] = cost[u] + wt;
                mnFlight[v] = 1 + mnFlight[u];
                mxFlight[v] = 1 + mxFlight[u];
                routes[v] = routes[u];
                s.insert({cost[v], v});
            }
            else if(cost[v] == cost[u] + wt){
                mnFlight[v] = min(mnFlight[v], mnFlight[u]+1);
                mxFlight[v] = max(mxFlight[v], mxFlight[u]+1);
                (routes[v] += routes[u]) %= mod;
                s.insert({cost[v], v});
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
        graph[a].push_back({b, wt});
    }

    dijkstra();

    print(cost[n], routes[n], mnFlight[n], mxFlight[n]);
 
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}