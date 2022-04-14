/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1619
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
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>>v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, i});
        v.push_back({b, i});
    }

    sort(v.begin(), v.end());

    unordered_map<int ,int> m;
    int curr = 0;
    for(int i = 0; i < v.size(); i++){
        auto [x, p] = v[i];
        if(m[p] == 0){
            m[p] = 1;
            curr++;
        }
        else if(m[p] == 1){
            m[p] = 0;
            curr--;
        }
        ans = max(ans, curr);
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
