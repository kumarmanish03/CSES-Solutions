/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1164/
* @refer: https://codeforces.com/blog/entry/83295
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
    q = n;

    multimap<pair<int, int>, int> m;
    for(int i = 0; i < n; i++){
        int a, d;
        cin >> a >> d;
        m.insert({{a,d},i});
    }

    int curr = 0;
    vector<int> res(n, 0);

    // {depart time, room no}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto [z, i]: m){
        auto [a, d] = z;
        if(!pq.empty() && pq.top().first < a){
            int r = pq.top().second;
            pq.pop();
            pq.push({d, r});
            res[i] = r;
        }
        else{
            curr++;
            pq.push({d, curr});
            res[i] = curr;
        }
    }

    print(curr);
    _print(res);
    
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