/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1744/
* @desc: we will try to cut 1*b 2*b ... a-1*b (same for b also) and get min from all
* @TC: O(ab(a+b))
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

int dp[505][505];
 
int func(int a, int b){
    if(a == b)
        return 0;

    if(dp[a][b] != -1)
        return dp[a][b];
 
    int cnt = LLONG_MAX;
    for(int k = 1; k < a; k++){
        cnt = min(cnt, 1 + func(k, b) + func(a-k, b));
    }
    for(int k = 1; k < b; k++){
        cnt = min(cnt, 1 + func(a, k) + func(a, b-k));
    }

    return dp[a][b] = cnt;
}

int solve(){
    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    print(func(a,b));
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    for(int i = 0; i < t; i++)
        solve();
}