/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1637/
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

int dp[1000005];

int func(int n){
    string s = to_string(n);

    if(s.size() == 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int steps = LLONG_MAX;
    for(int i = 0; i < s.size(); i++){
        int k = (s[i] - '0');
        if(k != 0)
            steps = min(steps, func(n - k) + 1);
    }

    return dp[n] = steps;
}

int solve(){
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    print(func(n));
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}