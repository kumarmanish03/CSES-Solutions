/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1630/
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
    int n, q;
    cin >> n;
    vector<pair<int, int>> v;
    q = n;
    int deadline = 0;
    while(q--){
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
        deadline += b;
    }

    sort(v.begin(), v.end());
    
    int finishTime = 0;
    for(auto [a, b]: v){
        finishTime += a * (n--);
    }

    print(deadline - finishTime);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}