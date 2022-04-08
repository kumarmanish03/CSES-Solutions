/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1715/
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
    string s;
    cin >> s;
    int n = s.size();
    int l = n;
    unordered_map<char, int> mmc;
    for(char c:s)
        mmc[c]++;

    vector<int> v;
    for(auto i:mmc)
        v.pb(i.sc);

    int ans = 1;
    int i = 0;
    int t = 1;
    for(int k = 1; k <= n; k++){
        ans = ans * l % m;
        ans = ans * binExp(t, m-2) % m;
        if(v[i] == t){
            i++;
            t = 1;
        }
        else
            t++;
        l -= 1;
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
