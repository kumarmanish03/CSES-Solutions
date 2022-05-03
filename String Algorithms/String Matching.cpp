/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1753/
* @refer: https://www.youtube.com/watch?v=ziteu2FpYsA&ab_channel=TECHDOSE
* @desc: using KMP algo
* @TC: O(m + n)
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
    string p, t;
    cin >> t >> p;

    string s = p + '#' + t;

    vector<int> kmp(s.size(), 0);
    for(int i = 1; i < s.size(); i++){
        int j = kmp[i-1];
        while(j > 0 && s[i] != s[j])
            j = kmp[j-1];
        if(s[i] == s[j])
            j++;
        kmp[i] = j;
    }

    int ans = count(kmp.begin(), kmp.end(), p.size());
    print(ans);
    
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}