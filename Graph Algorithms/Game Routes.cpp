/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1681/
* @TC: O(V + E)
* @topic: dp with graph
* @desc: cnt[u]: stores no. of ways we can go node u to n
    # If we reach already visited node then we add its count
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
vector<int> graph[N];
vector<bool> vis(N, 0);
vector<int> cnt(N, 0);
int n;

int dfs(int u){
    vis[u] = true;

    if(u == n){
        return cnt[u] = 1;
    }

    int res = 0;
    for(int v: graph[u]){
        if(vis[v]){
            (res += cnt[v]) %= mod;
        }
        else{
            (res += dfs(v)) %= mod;
        }
    }

    return cnt[u] = res;
}

int solve(){
    int m;
    cin >> n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1);
    
    cout << cnt[1];
 
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}