// Manish Kumar, IIIT Allahabad
// TC: O(logn)
// calculate fibonacci in log(n)

https://cses.fi/problemset/task/1722/
 
#include<bits/stdc++.h>
using namespace std;
 
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
 
#define int long long
const int m = 1e9+7;
 
// return {fibo(n), fibo(n+1)}
pair<int, int> fibo(int n){
    if(n == 0)
        return {0, 1};
 
    // p = {fibo(n/2), fibo(n/2 + 1)};
    auto [a, b] = fibo(n >> 1);
    int c = a * (2 * b - a) % m;
    int d = ((b * b) % m + (a * a) % m) % m;
    if(n&1){
        return {d, c + d};
    }
    else{
        return {c, d};
    }
}
 
int solve(){
    int n;
    cin >> n;
    
    print(fibo(n).first);
    
    return 0;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    // cin>>t;
    while(t--) solve();
}