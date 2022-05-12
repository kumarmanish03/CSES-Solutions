/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1097/
* @desc: Trick in this question is deciding how we play optimally
* 1st player try to maximize (score1 - score2) while 2nd try to minimize it
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

int func(int i, int j, bool first, vector<int> &v){
    if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(first)
        return dp[i][j] = max(v[i] + func(i+1, j, !first, v), v[j] + func(i, j-1, !first, v));
    else
        return dp[i][j] = min(-v[i] + func(i+1, j, !first, v), -v[j] + func(i, j-1, !first, v));
}

int solve(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> v(n);
    for(int &x:v){
        cin >> x;
        sum += x;
    }
    
    memset(dp, -1, sizeof(dp));
    int diff = func(0, n-1, true, v);
    print((sum + diff) / 2);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}