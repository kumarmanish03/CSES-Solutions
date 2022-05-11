/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1638/
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

const int mod = 1e9+7;

char v[1005][1005];
int dp[1005][1005];
int n;

int func(int i, int j){
    if(i == n-1 && j == n-1)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int cnt = 0;
    if(i+1 < n && v[i+1][j] == '.')
        (cnt += func(i+1, j)) %= mod;
    if(j+1 < n && v[i][j+1] == '.')
        (cnt += func(i, j+1)) %= mod;

    return dp[i][j] = cnt;
}

int solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = v[0][0] == '*' ? 0 : func(0, 0);
    print(ans);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}