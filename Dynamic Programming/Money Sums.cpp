/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1745
* @desc: we are using dp just to memorize states
* Also there may same sum multiple times, so we are using 'set'
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

bool dp[105][100005];

set<int> s;

bool func(int i, int sum, vector<int>&v){
    if(i == v.size()){
        s.insert(sum);
        return true;
    }

    if(dp[i][sum] == true)
        return dp[i][sum];

    return dp[i][sum] = func(i+1, sum + v[i], v) && func(i+1, sum, v);
}

int solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    memset(dp, false, sizeof(dp));
    func(0, 0, v);

    // erase 0
    s.erase(s.begin());

    print(s.size());
    for(auto i:s)
        cout << i << " ";
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}