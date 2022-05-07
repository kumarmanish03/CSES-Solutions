/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2107
* @desc: Implementation of Z-Algo and Kmp Algo
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
    string s;
    cin >> s;
    int n = s.size();

    vector<int> z(n, 0), kmp(n, 0);

    // z-Algo
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r)
            z[i] = min(z[i-l], r-i+1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i+z[i]-1 > r)
            l = i, r = i + z[i] - 1;
    }

    // Kmp-Algo
    for(int i = 1; i < n; i++){
        int j = kmp[i-1];
        while(j > 0 && s[i] != s[j])
            j = kmp[j-1];
        if(s[i] == s[j])
            kmp[i] = j+1;
        else
            kmp[i] = j;
    }
    
    _print(z);
    _print(kmp);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    for(int i = 0; i < t; i++)
        solve();
}