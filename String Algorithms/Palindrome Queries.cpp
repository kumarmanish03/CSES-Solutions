/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2420/
* @desc: stored hashes of string into two fenwick trees 
* [1st for forward string & 2nd for backward string]
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

const int N = 2e5+1;
const int mod = 1e9+7;
int p = 31;
int pw[N+1];

struct {
    int bit[N+5];

    int getHash(int i){
        int ans = 0;
        for(; i > 0; i -= (-i&i))
            ans = (ans + bit[i]) % mod;
        return ans;
    }

    void update(int i, int val){
        val %= mod;
        if(val < mod) val += mod;
        for(; i<N+5; i+=(-i&i)){
            bit[i] = (bit[i] + val) % mod;
        }
    }

} pre, suf;

int solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    pw[0] = 1;
    for(int i = 1; i < N+1; i++){
        pw[i] = pw[i-1] * p % mod;
    }

    for(int i = 0; i < n; i++){
        pre.update(i+1, (s[i]-'a'+1) * pw[i]);
        suf.update(i+1, (s[i]-'a'+1) * pw[n-i-1]);
    }

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k;
            char x;
            cin >> k >> x;
            pre.update(k, -(s[k-1]-'a'+1)*pw[k-1]);
            suf.update(k, -(s[k-1]-'a'+1)*pw[n-k]);
            s[k-1] = x;
            pre.update(k, (s[k-1]-'a'+1)*pw[k-1]);
            suf.update(k, (s[k-1]-'a'+1)*pw[n-k]);
        }
        else{
            int l, r;
            cin >> l >> r;
            int h1 = (pre.getHash(r) - pre.getHash(l-1) + mod) % mod;
            int h2 = (suf.getHash(r) - suf.getHash(l-1) + mod) % mod;
            if(h1 * pw[n-r] % mod == h2 * pw[l-1] % mod)
                print("YES");
            else
                print("NO");
        }
    }

    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}