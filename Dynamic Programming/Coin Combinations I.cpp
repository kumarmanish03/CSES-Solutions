/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1635/
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

const int mod = 1e9+7;

int solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    sort(v.begin(), v.end());

    vector<int> ways(sum + 1, 0);
    ways[0] = 1;
    for(int i = 1; i < sum+1; i++){
        for(auto c:v){
            if(i - c >= 0){
                ways[i] = (ways[i] % mod + ways[i-c] % mod) % mod;
            }
            else
                break;
        }
    }

    print(ways[sum]);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}