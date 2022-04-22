/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2428
* @refer: https://www.interviewbit.com/problems/counting-subarrays/
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
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    map<int, int> m;
    
    int i = 0;
    for(int j = 0; j < n; j++){
      m[v[j]]++;

      while(m.size() > k){
        if(m[v[i]] == 1)
          m.erase(m.find(v[i]));
        else
          m[v[i]]--;
        i++;
      }
      
      cnt += j - i + 1;
    }

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