/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1647/
* @logic: Sparse Table
* @refer: https://cp-algorithms.com/data_structures/sparse-table.html#range-sum-queries
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

int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n), log(n+1);
    for(int &x:v)
        cin >> x;

    log[1] = 0;
    for(int i = 2; i < n+1; i++)
        log[i] = log[i/2] + 1; 

    int sparse[n+1][25] = {0};
    // memset(sparse, INT_MAX, sizeof(sparse));

    for(int i = 0; i < n; i++)
        sparse[i][0] = v[i];

    for(int j = 1; j < 25; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = log[b - a + 1];
        int ans = min(sparse[a][l], sparse[b - (1 << l) + 1][l]);
        print(ans);
    }
    
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin>>t;
    for(int i = 0; i < t; i++)
        solve();
}
