// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/1642

// Using faster hash map then unordered_map

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

struct chash { 

    const uint64_t C = ll(2e18*acos((long double)-1))+71; 

    const int RANDOM = rand();

    ll operator()(ll x) const { 

        return __builtin_bswap64((x^RANDOM)*C); }

};


template<class K,class V> using ht = gp_hash_table<K,V,chash>;

int solve(){
    int n, sum = 0, check = 0;
    cin >> n >> sum;
    vector<int>v(n);
    for(int &i:v){
        cin >> i;
        check += i;
    }

    ht<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(m.find(sum - v[i] - v[j]) != m.end()){
                auto [k, l] = m[sum - v[i] - v[j]];
                if(k != i && k != j && l != i && l != j){
                    print(i+1, j+1, k+1, l+1);
                    return 0;
                }
            }
        }
        for(int j = i + 1; j < n; j++) m[v[i] + v[j]] = {i, j};
    }

    print("IMPOSSIBLE");
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin>>t;
    while(t--) solve();
}
