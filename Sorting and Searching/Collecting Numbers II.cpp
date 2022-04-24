/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2217/
* @refer: https://www.youtube.com/watch?v=LEL3HW4dQew&ab_channel=ARSLONGAVITABREVIS
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
    cin >> n >> q;
    int round = 1;
    vector<int> value(n+1), pos(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> value[i];
        pos[value[i]] = i;
    }

    for(int i = 2; i <= n; i++)
        round += (pos[i-1] > pos[i]);

    set<pair<int, int>> unique;
    while(q--){
        unique.clear();
        int i, j;
        cin >> i >> j;
        
        if(value[i]+1 <= n)
            unique.insert({value[i], value[i]+1});
        if(value[i]-1 >= 1)
            unique.insert({value[i]-1, value[i]});
        if(value[j]+1 <= n)
            unique.insert({value[j], value[j]+1});
        if(value[j]-1 >= 1)
            unique.insert({value[j]-1, value[j]});

        // Undo previous changes
        for(auto [a,b]:unique){
            round -= (pos[a] > pos[b]);
        }

        // swap values
        swap(value[i], value[j]);
        pos[value[i]] = i;
        pos[value[j]] = j;

        // make changes acc to new values
        for(auto [a,b]:unique){
            round += (pos[a] > pos[b]);
        }

        print(round);
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