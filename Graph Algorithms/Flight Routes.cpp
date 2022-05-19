/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1671/
* @desc: Dijkstra Algo Modified -> find k shortest distance
    # we maintain a processed array which maintains no. of times it is visited
    # we only processed each node k times else ignore it
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

const int N = 1e5+5;
vector<pair<int, int>> graph[N];
vector<int> processed(N, 0);
vector<int> cost(N, INF);
int n, m, k;
vector<int> routes;

void dijkstra(){
    multiset<pair<int, int>> s;
    s.insert({0, 1});

    while(!s.empty()){
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        // For des node insert its distance in ans array
        if(u == n && processed[n] < k){
            routes.pb(d);
        }

        // If node already reached k times then ignore
        if(processed[u] == k) continue;

        processed[u]++;
        for(auto [v, wt]: graph[u]){
            s.insert({d+wt, v});
        }
    }
}

int solve(){
    cin >> n >> m >> k;
    int a, b, wt;
    while(m--){ 
        cin >> a >> b >> wt;
        if(a == b) continue;

        graph[a].push_back({b, wt});
    }

    dijkstra();

    _print(routes);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}