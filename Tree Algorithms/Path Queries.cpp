/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1138/
* @topic: Euler Tour / flattening a tree, Difference Array and Fenwick Tree
* @desc: 
*  # dfs(): stores sum of values on the path from the root to each node
*  # dfs2(): flattening a tree
*  # Observation: if value of node u changes then it will affect ans of its subtree nodes only
*  # Then in flattened tree we add +val at start[u] and -val(to neutralize it) at endd[u]+1
*  # Hence final answer original + pathSum[u] + (sum of changes made till subtree node)
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

int n;
const int N = 2e5+5;
vector<int> tree[N];
vector<int> start(N, 0);
vector<int> endd(N, 0);
vector<int> bit(N, 0);
vector<int> value(N, 0);
vector<int> pathSum(N, 0);
int timer;

void dfs(int u, int p){
    pathSum[u] += value[u];
    for(auto v: tree[u]){
        if(v == p) continue;
        pathSum[v] += pathSum[u];
        dfs(v, u);
    }
}

void dfs2(int u, int p){
    start[u] = ++timer;

    for(int v: tree[u]){
        if(v == p) continue;
        dfs2(v, u);
    }

    endd[u] = timer;
}

int sum(int i){
    int ans = 0;
    for(; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void update(int i, int val){
    for(; i < N; i += (i & -i))
        bit[i] += val;
}

int solve(){
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> value[i];

    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1);

    timer = 0;
    dfs2(1, -1);
    
    int t;
    while(q--){
        cin >> t;
        if(t == 1){
            int u, val;
            cin >> u >> val;
            update(start[u], val - value[u]);
            update(endd[u]+1, -(val - value[u]));
            value[u] = val;
        }
        else{
            int u;
            cin >> u;
            print(pathSum[u] + sum(start[u]));
        }
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