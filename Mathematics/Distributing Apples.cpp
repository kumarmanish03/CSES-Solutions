/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1716
* @logic:
*   Number of ways in which n identical objects can be divided into r groups where each group can have any number of objects, including 0.
*   The formula is (n+r-1) C (r-1).
* @explaination:
*   Consider that the number of identical objects is n. Now consider that all these n objects are placed in a row. 
*   Let us assume some separators that separates the n objects. Now as we want to separate them into r group [as blank groups are also allowed],
*   take the separators as objects. Now we need r-1 separators to make r groups. Therefore total number of objects is n+r-1. 
*   There will be r-1 places for the separators to occupy. Therefore we can arrange the separators in (n+r-1) C (r-1) ways,
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

const int m = 1e9+7;

int binExp(int a, int b){
    int res = 1;
    a %= m;
    while(b){
        if(b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int solve(){
    int n, mm, ans = 1;
    cin >> n >> mm;
    
    int a = n + mm - 1;
    int b = n - 1;

    for(int i = 1; i <= b; i++){
        ans = ans * (a - i + 1) % m;
        ans = ans * binExp(i, m-2) % m;
    }

    print(ans);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin>>t;
    for(int i = 0; i < t; i++)
        solve();
}
