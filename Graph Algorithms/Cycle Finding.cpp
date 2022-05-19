/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1197/
* @desc: -ve weight cycle detection using Bellman ford algo
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

const int N = 2505;
vector<vector<int>> edges;
vector<int> cost(N, INF);
vector<int> parent(N, -1);
int n, m;
int cycleNode;

void bellman_ford(){
    cost[1] = 0;
    cycleNode = -1;
    for(int i = 0; i < n; i++){
        for(auto edge: edges){
            int src = edge[0];
            int des = edge[1];
            int wt = edge[2];
            if(cost[src] + wt < cost[des]){
                cost[des] = wt + cost[src];
                parent[des] = src;

                if(i == n-1){
                    cycleNode = des;
                }
            }
        }
    }
}

int solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({a, b, wt});
    }  

    bellman_ford();  

    if(cycleNode != -1){
        print("YES");

        int x = cycleNode;
        for (int i = 0; i < n; ++i)
            x = parent[x];

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        for (int v : cycle)
            cout << v << ' ';
    }
    else{
        print("NO");
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