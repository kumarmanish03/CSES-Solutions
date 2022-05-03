/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1732
* @desc: using KMP algo and observation
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
    vector<int> ans;

    vector<int> kmp(s.size(), 0);
    for(int i = 1; i < s.size(); i++){
        int j = kmp[i-1];
        while(j > 0 && s[i] != s[j])
            j = kmp[j-1];
        if(s[i] == s[j])
            j++;
        kmp[i] = j;
    }

    int k = kmp.size()-1;
    while(kmp[k] != 0){
        ans.push_back(kmp[k]);
        k = kmp[k]-1;
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << *it << " ";
    }
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}