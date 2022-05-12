/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1746/
* @desc: [given in comments below]
* @TC: O(n*m)
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

int dp[100005][105];

int m;
int n;

int func(int i, int prev, vector<int>&v){
    // If reached all elements then add it to answer
    if(i == n)
        return 1;

    if(dp[i][prev] != -1)
        return dp[i][prev];

    int ans = 0;

    if(v[i] != 0){
        // if v[i] is valid as per prev -> moving ahead
        // or if i=0 & v[i]!=0 -> moving ahead
        // else return 0 (becoz abs(v[i]-pev) > 1 -> hence not valid)
        if(abs(v[i]-prev) <= 1 || i == 0)
            return dp[i][prev] = func(i+1, v[i], v);
        else
            return dp[i][prev] = 0;
    }

    // for first index we are trying to set value from 1 to m
    if(i == 0){
        int cnt = 0;
        for(int k = 1; k <= m; k++)
            (cnt += func(i+1, k, v)) %= mod;
        return dp[i][prev] = cnt;
    }

    // at 'i' index we are trying to set value {prev-1, prev, prev+1} (previous value) 
    int cnt = func(i+1, prev, v);
    if(prev-1 >= 1)
        (cnt += func(i+1, prev-1, v)) %= mod;
    if(prev+1 <= m)
        (cnt += func(i+1, prev+1, v)) %= mod;
    return dp[i][prev] = cnt;
}

int solve(){
    cin >> n >> m;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    memset(dp, -1, sizeof(dp));
    print(func(0, 101, v));
    
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}