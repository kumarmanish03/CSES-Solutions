/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1662
* @refer: https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/
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
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    map<int, int> mod;
    
    int curr = 0;
    for(int i = 0; i < n; i++){
      curr += v[i];
      mod[((curr % n) + n) % n]++;
    }

    // getting count of all possible mods
    for(int i = 0; i < n; i++){
      if(mod[i] > 1)
        cnt += (mod[i] * (mod[i]-1)) / 2;
    }

    cnt += mod[0];

    print(cnt);
    
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