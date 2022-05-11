/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1158/
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

int solve(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int &x:price)
        cin >> x;
    for(int &x:pages)
        cin >> x;

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
 
    for(int i = 1; i <= n; i++){
        for(int wt = 0; wt <= x; wt++){
            if(wt >= price[i-1])
                dp[i][wt] = max(pages[i-1] + dp[i-1][wt-price[i-1]], dp[i-1][wt]);
            else
                dp[i][wt] = dp[i-1][wt];
        }
    }

    print(dp[n][x]);
    
    
    return 0;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}