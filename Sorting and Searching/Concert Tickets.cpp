// https://cses.fi/problemset/task/1091

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
    int n, m;
    cin >> n >> m;
    vector<int> v(n), t(m);
    for(int &x:v)
        cin >> x;
    for(int &x:t)
        cin >> x;
 
    multiset<int> s;
 
    for(int x:v)
        s.insert(x);
 
    for(int x:t){
        auto it = s.upper_bound(x);
        if(it == s.begin())
            print(-1);
        else{
            it--;
            print(*it);
            s.erase(it);
        }
    }
 
    
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
