/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1090
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
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    sort(v.begin(), v.end());

    int res = 0;
    int i = 0, j = n-1;
    while(i <= j){
        if(v[i] + v[j] <= w){
            i++;
            j--;
            res++;
        }
        else{
            j--;
            res++;
        }
    }

    print(res);
    
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
