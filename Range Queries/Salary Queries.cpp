/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1144/
* @desc: this question is simple using ordered_set
*
*/

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    ordered_set s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        s.insert({v[i], i});
    }

    char c;
    while(q--){
        cin >> c;
        if(c == '!'){
            int k, x;
            cin >> k >> x;
            auto it = s.find({v[k-1], k-1});
            s.erase(it);
            v[k-1] = x;
            s.insert({x, k-1});
        }
        else{
            int a, b;
            cin >> a >> b;
            int cnt = s.order_of_key({b, 2e5+5}) - s.order_of_key({a, -1});
            print(cnt);
        }
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