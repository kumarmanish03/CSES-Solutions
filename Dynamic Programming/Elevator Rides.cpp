/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1653/
* @topic: DP with bitmask
* @refer: https://cses.fi/book/book.pdf [pg-103]
* @desc: [in comments]
* TC: O(2^n * n)
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
// #define int long long

int solve(){
    int n, weight;
    cin >> n >> weight;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    // dp[i] = {minRides, lastWt} stores rides till i person and 'lastwt' stores wt of last rides 
    vector<pair<int, int>> dp(1 << n, {25, 1e9+5});
    // first ride is 1 with last ride weight is 0
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1 << n); mask++){

        for(int i = 0; i < n; i++){
            // if i is present in currenct mask set
            if(mask & (1 << i)){
                // min rides if v[i] is not in set
                auto [minRides, lastWt] =  dp[mask ^ (1 << i)];
                if(lastWt + v[i] <= weight){
                    dp[mask] = min(dp[mask], {minRides, lastWt + v[i]});
                }
                else{
                    dp[mask] = min(dp[mask], {minRides+1, v[i]});
                }
            }
        }
    }

    print(dp[(1 << n) - 1].first);
    
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}