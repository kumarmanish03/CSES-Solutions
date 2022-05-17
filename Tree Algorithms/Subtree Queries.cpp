/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1137/
* @TC: O(nlogn)
* @topic: Euler tour / flatting tree & Fenwick tree
* @refer: https://codeforces.com/blog/entry/79048
* @desc: B/w (start[u], endd[u]) constains all nodes of subtree u
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

const int N = 2e5+5;
vector<int> tree[N];
vector<int> value(N, 0);
vector<int> start(N, 0);
vector<int> endd(N, 0);
vector<int> flat_tree(N, 0);
vector<int> bit(N, 0);
int timer;


// flatting the tree 
void dfs(int u, int p){
    start[u] = ++timer;
    flat_tree[timer] = u;
    for(int v: tree[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    endd[u] = timer;
}

// Fenwick Tree
int sum(int i){
    int ans = 0;
    for(; i > 0; i-=(i & -i)){
        ans += bit[i];
    }
    return ans;
}

void update(int i, int val){
    for(; i<=N; i+=(i&-i)){
        bit[i] += val;
    }
}

int solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> value[i];

    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    timer = 0;
    dfs(1, -1);

    // we can see flat tree here
    // for(int i = 1; i<= n; i++)
    //     print(flat_tree[i], start1[flat_tree[i]], end1[flat_tree[i]]);


    // construct fenwick tree
    for(int i = 1; i <= n; i++){
        update(i, value[flat_tree[i]]);
    }

    int t;
    while(q--){
        cin >> t;
        if(t == 1){
            int u, val;
            cin >> u >> val;
            update(start[u], val - value[u]);
            value[u] = val;
        }
        else{
            int u;
            cin >> u;
            print(sum(endd[u]) - sum(start[u] - 1));
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