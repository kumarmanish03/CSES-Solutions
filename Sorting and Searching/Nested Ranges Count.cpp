/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2169/
* @refer: https://www.youtube.com/watch?v=ORdmSirqrMs&ab_channel=ARSLONGAVITABREVIS
*
*/

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

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

    ordered_set maxB;

    for(int i = 0; i < n; i++){
        auto [a,b] = item[i];
        // no. of elements greater than qual to b
        int cnt = maxB.size()-maxB.order_of_key({b, -i});
        if(cnt){
            int idx = mp[{a, b}];
            res2[idx] = cnt;
        }
        maxB.insert({b, -i});
    }

    ordered_set minB;

    for(int i = n-1; i >= 0; i--){
        auto [a,b] = item[i];
        // no. of elements lesser than equal to b
        int cnt = minB.order_of_key({b, -i});
        if(cnt){
            int idx = mp[{a, b}];
            res1[idx] = cnt;
        }
        minB.insert({b, -i});
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