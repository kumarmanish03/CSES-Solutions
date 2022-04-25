/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1632/
* @refer: https://www.youtube.com/watch?v=hitZrt5OlLs&ab_channel=ARSLONGAVITABREVIS
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
    int n, k, q;
    cin >> n >> k;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }

    sort(v.begin(), v.end(), [](auto i, auto j){
        if(i.sc == j.sc)
            return i.fs < j.fs;
        return i.sc < j.sc;
    });

    int watched = 0;
    set<pair<int,int>> s;

    int i = 1;
    for(auto [a,b]: v){
        // checks for movie whose ending time is less than or equal to a
        // and if not found and less than k people watching then watch that movie, else skip 
        auto it = s.lower_bound({a*-1, -1});
        if(it != s.end()){
            s.erase(it);
            s.insert({b*-1, i});
            watched++;
        }
        else if(s.size() < k){
            s.insert({b*-1, i});
            watched++;
        }

        i++;
    }

    print(watched);
    
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