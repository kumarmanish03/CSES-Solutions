/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1639/
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

int dp[5005][5005];

int func(int i, int j, string& s1, string& s2){
    if(i == s1.size() || j == s2.size()){
        return (s1.size()-i + s2.size()-j);
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] != s2[j]){
        return dp[i][j] = min(1 + func(i+1, j, s1, s2), min(1 + func(i, j+1, s1, s2), 1 + func(i+1, j+1, s1, s2)));
    }
    else
        return dp[i][j] = func(i+1, j+1, s1, s2);
}

int solve(){
    string s1, s2;
    cin >> s1 >> s2;

    memset(dp, -1, sizeof(dp));
    print(func(0, 0, s1, s2));
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    for(int i = 0; i < t; i++)
        solve();
}