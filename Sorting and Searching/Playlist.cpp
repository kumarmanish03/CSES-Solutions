/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1141/
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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    map<int, int> m;
    int i = 0;
    int mx = 0;
    for(int j = 0; j < n; j++){
        m[v[j]]++;

        while(m.size() < j-i+1){
            if(m[v[i]] <= 1)
                m.erase(v[i]);
            else
                m[v[i]]--;
            i++;
        }

        mx = max(mx, (int)m.size());
    }

    print(mx);
    
    
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