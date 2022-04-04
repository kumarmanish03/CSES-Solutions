// Manish Kumar, IIIT Allahabad
// 2 pointer approach

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

// #define int long long

int solve(){
    int n, sum = 0;
    cin >> n >> sum;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int reqSum = sum - v[i].first;
        int l = i+1, r = n-1;
        while(l < r){
            if(v[l].first + v[r].first < reqSum)
                l++;
            else if(v[l].first + v[r].first > reqSum)
                r--;
            else{
                print(v[i].second+1, v[l].second+1, v[r].second+1);
                return 0;
            }
        }
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
