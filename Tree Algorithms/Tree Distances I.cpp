/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1132/
* @refer: https://www.youtube.com/watch?v=Rnv4qvoxsTo&ab_channel=HiteshTripathi
* @desc: 
*  # First we are calulating distance to all nodes from a random node(ex 1);
*  # Maximum distance node is surely be one of the diameter node
*  # So we got one of the diameter node which is 'node1'
*  # Similarly we call dfs from node1 and then maxminum distance node from this is surely be another diameter node i.e, 'node2'
*  # A Good Observation for this problem is that: for each node its maximum distance is from one of the diameter nodes of this tree
*  # So we calculate distance of all nodes from each of diameter nodes
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

const int N = 2e5+5;

// calculates distance of all nodes from node it is called and saves distance in 'dis' vector
void dfs(int u, int d, int p, vector<int>& dis, vector<vector<int>> &adj){

    dis[u] = d;
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, d+1, u, dis, adj);
    }
}

int solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dis;

    // Finding one of the diameter node 'node1'
    dis.resize(n+1, 0);
    dfs(1, 0, -1, dis, adj);
    int node1_dis = 0;
    int node1 = 0;
    for(int u = 1; u <= n; u++){
        if(node1_dis < dis[u]){
            node1 = u;
            node1_dis = dis[u];
        }
    }

    // Using 'node1' finding another diameter node 'node2'
    dis.resize(n+1, 0);
    dfs(node1, 0, -1, dis, adj);
    int node2_dis = 0;
    int node2 = 0;
    for(int u = 1; u <= n; u++){
        if(node2_dis < dis[u]){
            node2 = u;
            node2_dis = dis[u];
        }
    }

    // Now we got node1 & node2
    vector<int> d1(n+1, 0); // d1[u]: stores distance of node u from node1
    vector<int> d2(n+1, 0); // d2[u]: stores distance of node u from node2
    dfs(node1, 0, -1, d1, adj);
    dfs(node2, 0, -1, d2, adj);

    for(int i = 1; i <= n; i++){
        cout << max(d1[i], d2[i]) << " ";
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