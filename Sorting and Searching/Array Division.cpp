/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1085/
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

bool check(int x, vector<int> &v, int k){
  int cnt = 1, temp = 0;
  for(int i = 0; i < v.size(); i++){

    if(v[i] > x) return false;

    if(v[i] + temp <= x)
      temp += v[i];
    else{
      cnt++;
      temp = v[i];
    }
  }
  return (cnt <= k);
}

int solve(){
    int n, k, lo = INT_MAX, hi = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x:v){
        cin >> x;
        lo = min(lo, x);
        hi += x;
    }
    
    while(hi - lo > 1){
      int mid = (hi + lo) / 2;
      if(check(mid, v, k)){
        hi = mid;
      }
      else{
        lo = mid+1;
      }
    }

    if(check(lo, v, k))
      print(lo);
    else if(check(hi, v, k))
      print(hi);
    else
      print(-1);
    
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