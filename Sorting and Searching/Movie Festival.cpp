/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1629/
* @refer: https://codeforces.com/blog/entry/83295
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
    int n;
    cin >> n;
    vector<pair<int, int>> mov;
    while(n--){
        int a, b;
        cin >> a >> b;
        mov.pb({a,b});
    }
    
    sort(mov.begin(), mov.end(), [](auto a, auto b){
        if(a.sc == b.fs)
            return a.fs < b.fs;
        return a.sc < b.sc;
    });

    int temp = 0, res = 0;
    for(auto [s,e]: mov){
        if(temp <= s){
            res++;
            temp = e;
        }
    }

    print(res);
    
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