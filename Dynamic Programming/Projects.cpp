/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1140/
* @refer: https://codeforces.com/blog/entry/70018
* @topic: coordinate compression, dynamic programming dp
* @desc: we compress dates that made them into <1e5, then save projects data acc. to their finishing date
* and calculate dp[i] = max amount of money till 'i'th day
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

int solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    map<int, int> compress;
    for(auto &x:v){
        cin >> x[0] >> x[1] >> x[2];
        compress[x[0]];
        compress[x[1]];
    }

    int ind = 1;
    for(auto &x: compress){
        x.second = ind++;
    }

    vector<pair<int, int>> projects[ind];
    for(int i = 0; i < n; i++){
        projects[compress[v[i][1]]].push_back({compress[v[i][0]], v[i][2]});
    }

    // Dp[i] = max amount of money till 'i'th day
    vector<int> dp(ind, 0);
    for(int i = 1; i < ind; i++){
        if(i > 0)
            dp[i] = dp[i-1];
        for(auto p: projects[i]){
            dp[i] = max(dp[i], dp[p.first-1] + p.second);
        }
    }

    print(dp[ind-1]);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}