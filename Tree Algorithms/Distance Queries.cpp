/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1688/
* @desc: using lca, lowest common ancestor
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
int up[N][20];
int level[N];

// to find levels of each node
void dfs(int u, int p){

    for(int v: tree[u]){
        if(v == p) continue;
        level[v] = 1 + level[u];
        dfs(v, u);
    }
}

void binary_lifting(int u, int p){
    up[u][0] = p;
    for(int k = 1; k < 20; k++){
        if(up[u][k-1] != -1){
            up[u][k] = up[up[u][k-1]][k-1];
        }
        else{
            up[u][k] = -1;
        }
    }

    for(int v: tree[u]){
        if(v == p) continue;
        binary_lifting(v, u);
    }
}

int ancestor(int u, int jump){
    if(u == -1 || jump == 0)
        return u;

    for(int i = 19; i >= 0; i--){
        if(jump >= (1 << i)){
            return ancestor(up[u][i], jump - (1 << i));
        }
    }

    return -1;
}

int LCA(int a, int b){
    if(level[a] < level[b])
        swap(a, b);

    a = ancestor(a, level[a] - level[b]);

    // if one of the a & b node is lca
    if(a == b) 
        return a;

    for(int k = 19; k >= 0; k--){
        if(up[a][k] != up[b][k]){
            a = up[a][k];
            b = up[b][k];
        }
    }

    return up[a][0];
}

int solve(){
    int n, q;
    cin >> n >> q;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    level[1] = 0;
    dfs(1, -1);
    binary_lifting(1, -1);

    while(q--){
        int a, b;
        cin >> a >> b;
        int lca = level[LCA(a,b)];
        cout << (level[a] - lca) + (level[b] - lca) << "\n";
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