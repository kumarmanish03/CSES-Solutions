/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1084
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int &x:a)
        cin >> x;
    for(int &x:b)
        cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

        int i = 0, j = 0, ans = 0;
        while(i < a.size() && j < b.size()){
            if(a[i]-k <= b[j] && a[i]+k >= b[j]){
                i++;
                j++;
                ans++;
            }
            else if(b[j] < a[i]-k){
                j++;
            }
            else if(b[j] > a[i]+k){
                i++;
            }
        }

    print(ans);

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
