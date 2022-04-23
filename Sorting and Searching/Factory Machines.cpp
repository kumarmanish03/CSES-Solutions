/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1620/
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

bool check(int x, vector<int> &v, int t){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += (x / v[i]);
    }

    return (cnt >= t);
}

int solve(){
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    int lo = 1, hi = *min_element(v.begin(), v.end()) * t;
    int ans = -1;
    while(lo <= hi){
        int mid = (hi + lo) / 2;
        if(check(mid, v, t)){
            hi = mid-1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
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