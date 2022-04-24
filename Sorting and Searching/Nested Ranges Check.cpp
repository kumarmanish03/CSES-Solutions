/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2168/
* @refer: https://www.youtube.com/watch?v=upDipax6xDU&ab_channel=ARSLONGAVITABREVIS
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
// #define int long long

int solve(){
    int n, q;
    cin >> n;
    vector<int> res1(n, 0), res2(n, 0);
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> item;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        item.pb({a, b});
        mp.insert({{a,b},i});
    }

    sort(item.begin(), item.end(), [=](auto i, auto j){
        if(i.fs == j.fs)
            return i.sc > j.sc;
        return i.fs < j.fs;
    });

    int maxB = 0;

    for(int i = 0; i < n; i++){
        auto [a,b] = item[i];
        if(b <= maxB){
            int idx = mp[{a, b}];
            res2[idx] = 1;
        }
        maxB = max(maxB, b);
    }

    int minB = INT_MAX;

    for(int i = n-1; i >= 0; i--){
        auto [a,b] = item[i];
        if(b >= minB){
            int idx = mp[{a, b}];
            res1[idx] = 1;
        }
        minB = min(minB, b);
    }

    _print(res1);
    _print(res2);

    
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