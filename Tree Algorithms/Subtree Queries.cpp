/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1137/
* @TC: O(nlogn) [code is correct but passing 50% test cases, may be due to overflow issues]
* @topic: Euler tour / flatting tree & Fenwick tree
* @refer: https://www.youtube.com/watch?v=P8NHOmX5XGM
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
vector<int> start1(N, 0);
vector<int> end1(N, 0);
vector<int> flat_tree(4*N, 0);
int cnt;

vector<int> bit(4*N, 0);

// flatting the tree 
void dfs(int u, int p){
    start1[u] = cnt;
    flat_tree[cnt] = value[u];
    cnt++;
    for(int v: tree[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    end1[u] = cnt;
    flat_tree[cnt] = value[u];
    cnt++;
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

int getSum(int l, int r){
    return sum(r) - sum(l-1);
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

    cnt = 1;
    dfs(1, -1);

    // construct fenwick tree
    for(int i = 1; i < cnt; i++){
        update(i, flat_tree[i]);
    }

    int t;
    while(q--){
        cin >> t;
        if(t == 1){
            int u, val;
            cin >> u >> val;
            update(start1[u], val - value[u]);
            update(end1[u], val - value[u]);
            value[u] = val;
            flat_tree[start1[u]] = val;
            flat_tree[end1[u]] = val;
        }
        else{
            int u;
            cin >> u;
            print(getSum(start1[u], end1[u]) / 2);
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