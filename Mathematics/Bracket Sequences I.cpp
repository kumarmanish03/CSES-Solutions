// Manish Kumar, IIIT Allahabad
// Using catalen no. formula

https://cses.fi/problemset/task/2064/

#include<bits/stdc++.h>
using namespace std;
 
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
 
#define int long long
 
// nth catalen no.[ Cn = 2nCn / (n+1) ]
 
const int m = 1e9+7;
int binExp(int a, int b){
    int res = 1;
    while(b){
        if(b&1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
int solve(){
    int n, ans = 1;
    cin >> n;
 
    if(n&1)
        print(0);
    else{
        n /= 2;
        if(n <= 1){
            print(1);
            return 0;
        }
        for(int i = 2; i <= n; i++){
            ans = ans * ((n+i) * binExp(i, m-2) % m) % m;
        }
        print(ans);
    }
    
    
    return 0;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    // cin>>t;
    while(t--) solve();
}