/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1652/
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
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    for(int i = 1; i < n+1; i++){
        string s;
        cin >> s;
        for(int j = 1; j < n+1; j++){
            v[i][j] = (s[j-1] == '*') ? 1 : 0;
        }
    }

    // taking prefix sum
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            v[i][j] += v[i-1][j];
        }
    }

    while(q--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1];
        print(sum);
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