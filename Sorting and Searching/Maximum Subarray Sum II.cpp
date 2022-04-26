/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1644/
* @refer: https://www.geeksforgeeks.org/maximum-sum-subarray-of-size-range-l-r/
* @desc: Using prefix sum (sliding window approach)
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
    int n, l, r, ans = LLONG_MIN;
    cin >> n >> l >> r;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    // prefix sum
    for(int i = 1; i < n; i++)
        v[i] += v[i-1];

    ans = max(ans, v[l-1]);

    multiset<int> ms;
    for(int i = l; i < n; i++){

        ms.insert(v[i-l]);
        ans = max(ans, v[i] - *ms.begin());

        if(i <= r-1){
            ans = max(ans, v[i]);
        }

        if(i >= r){
            ms.erase(ms.find(v[i-r]));
        }
    }

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