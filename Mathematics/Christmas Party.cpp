/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1717
* @hint: This is a standard problem of finding derangements in a sequence.
* The recursive formula is D(n)=(D(n−1)+D(n−2))(n−1).
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

int solve(){
    int n;
    cin >> n;

    int d[n+1] = {0};
    d[1] = 0;
    d[2] = 1;
    for(int i = 3; i < n+1; i++)
        d[i] = (d[i-1] + d[i-2] % m) * (i-1) % m;
    
    print(d[n]);

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
