/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1636/
* @refer: https://youtu.be/PoTE56n_It8?t=997
* @desc: This problem is different from 'Coin Combinations I' as in this question we have to count ordered ways
* Here first we solve for each coin then move to different coin
*
*/

/* Solution 1 (Iterative DP) */

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

const int mod = 1e9+7;

int dp[105][1000010];

int solve(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n, 0);
    for(int &x: coins)
        cin >> x;

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 105; i++)
        dp[i][0] = 1;

    for(int ind = 1; ind < n+1; ind++){
        for(int x = 1; x <= amount; x++){
            dp[ind][x] += dp[ind-1][x];
            if(x - coins[ind-1] >= 0)
                (dp[ind][x] += dp[ind][x - coins[ind-1]]) %= mod;
        }
    }

    print(dp[n][amount]);

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}

/* Solution 2 (Recursive DP) */

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

const int mod = 1e9+7;

int dp[105][1000010];

int func(int ind, int amount, vector<int> &coins){
    if(amount == 0)
        return 1;

    if(ind < 0 || amount < 0)
        return 0;

    if(dp[ind][amount] != -1)
        return dp[ind][amount];

    return dp[ind][amount] = (func(ind, amount - coins[ind], coins) % mod + func(ind-1, amount, coins) % mod) % mod;
}

int solve(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n, 0);
    for(int &x: coins)
        cin >> x;

    memset(dp, -1, sizeof(dp));
    print(func(n-1, amount, coins));
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}