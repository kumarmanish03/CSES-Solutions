/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1133/
* @refer: https://www.youtube.com/watch?v=nGhE4Ekmzbc&ab_channel=Luv
* @topic: using rerooting technique, tree with dp
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

// we assumed tree rooted at 1

// stores total no. of nodes in subtree i 
int totalNodes[N];
// stores the sum of the distances from the node to all child nodes
int sumOfNodes[N];
// [final ans]: stores the sum of the distances from the node to all other nodes
int ans[N];

// This function fill all values of totalNodes[N] & sumOfNodes[N]
void dfs(int u, int p, vector<vector<int>> &tree){

    totalNodes[u] = 1;
    sumOfNodes[u] = 0;
    for(auto v: tree[u]){
        if(v == p) continue;
        dfs(v, u, tree);
        totalNodes[u] += totalNodes[v];
        sumOfNodes[u] += sumOfNodes[v] + totalNodes[v];
    }

}

// This funcion calculates ans[N]
// 'par_ans': stores sum to all other nodes excluding subtree u [for more see video]
void dfs1(int u, int p, int par_ans, vector<vector<int>> &tree){

    ans[u] = sumOfNodes[u] + (par_ans + totalNodes[1] - totalNodes[u]);

    for(int v: tree[u]){
        if(v == p) continue;
        dfs1(v, u, ans[u] - (sumOfNodes[v] + totalNodes[v]), tree);
    }
}


int solve(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0, tree);
    dfs1(1, 0, 0, tree);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
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