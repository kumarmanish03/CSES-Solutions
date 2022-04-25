/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2162/
* @disc: observation
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
    
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.pb(i);

    bool even = true;
    while(v.size() > 1){
        // store elements that are not deleted
        vector<int> left;
        for(int i = 0; i < v.size(); i++){
            if(bool(i&1) == even)
                cout << v[i] << " ";
            else
                left.pb(v[i]);
        }
        // for odd size change parity
        if(v.size()%2 == 1)
            even = !even;
        v = left;
    }

    cout << v.back();
    
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