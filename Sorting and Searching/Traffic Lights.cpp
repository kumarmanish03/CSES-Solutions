/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1073/
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
    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    set<int> s;
    multiset<int>m;
    s.insert(0);
    s.insert(l);
    m.insert(l);
    for(auto i:v){
        auto it = s.lower_bound(i);
        auto it2 = it;
        it2--;
        m.erase(m.find(*it - *it2));
        m.insert(i - *it2);
        m.insert(*it - i);
        s.insert(i);
        cout << *m.rbegin() << " ";
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