/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1633/
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

int solve(){
    int n;
    cin >> n;
    
    int value[6] = {1,2,3,4,5,6};

    vector<int> count(n+1, 0);
    count[0] = 1;
    for(int i = 1; i <= n; i++){
        for(auto d:value){
            if(i-d >= 0){
                count[i] = (count[i] % mod + count[i-d] % mod) % mod;
            }
        }
    }

    print(count[n] % mod);

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}