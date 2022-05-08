/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1634/
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
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    vector<int> minCoins(sum+1, 0);
    minCoins[0] = 0;
    for(int i = 1; i <= sum; i++){
        int mn = LLONG_MAX;
        for(auto c:v){
            if((i-c >= 0) && (minCoins[i-c] != LLONG_MAX)){
                mn = min(minCoins[i-c] + 1, mn);
            }
        }
        minCoins[i] = mn;
    }
    
    print(minCoins[sum] == LLONG_MAX ? -1 : minCoins[sum]);

    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}