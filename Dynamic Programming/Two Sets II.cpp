/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1093/
* @desc: [given in comments]
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

int dp[505][130000];

int binExp(int a, int b){
    int res = 1;
    a %= mod;
    while(b){
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// This function gives count of sets having sum equal to 'sum'
int func(int i, int sum){
    if(sum == 0)
        return 1;
    if(sum < 0 || i == 0)
        return 0;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    return dp[i][sum] = (func(i-1, sum - i) + func(i-1, sum)) % mod;
}

int solve(){
    int n;
    cin >> n;
    
    int totalSum = (n * (n+1)) / 2;
    memset(dp, -1, sizeof(dp));
    if(totalSum & 1)
        print(0);
    else
        // divide ans / 2 becoz it will count other set again
        print(func(n, totalSum/2) * binExp(2, mod-2) % mod);

    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}