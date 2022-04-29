/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1190/
* @refer: https://codeforces.com/blog/entry/77128
* @topic: segment trees
* @level: hard
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
// {maxSubsum, maxPre, maxSuf, totalSum}
int segTree[4*N][4];
int n;

vector<int> combine(vector<int> &a, vector<int> &b){
    vector<int> res(4);
    res[0] = max(a[0], max(b[0], max(a[2] + b[1], 0LL)));
    res[1] = max(a[1], max(a[3]+b[1], 0LL));
    res[2] = max(b[2], max(a[2]+b[3], 0LL));
    res[3] = a[3] + b[3];
    return res;
}

void update(int pos, int val, int node = 0, int sl = 0, int sr = n-1){
    if(pos < sl || sr < pos)
        return;

    if(sl == sr){
        for(int i = 0 ; i < 3; i++)
            segTree[node][i] = (0LL,val);
        segTree[node][3] = val;
    }
    else{
        int mid = (sl + sr) / 2;
        update(pos, val, 2*mid+1, sl, mid);
        update(pos, val, 2*mid+2, mid+1, sr);
        int k = mid;
        segTree[node][0] = max({segTree[2*k+1][0], segTree[2*k+2][0], segTree[2*k+1][2] + segTree[2*k+2][1], 0LL}); //max
        segTree[node][1] = max({segTree[2*k+1][1], segTree[2*k+1][3] + segTree[2*k+2][1], 0LL}); //pre
        segTree[node][2] = max({segTree[2*k+1][2] + segTree[2*k+2][3], segTree[2*k+2][2], 0LL}); //suff
        segTree[node][3] = segTree[2*k+1][3] + segTree[2*k+2][3]; //total
    }
}

int solve(){
    int q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i<n;i++){
        cin >> v[i];
        update(i, v[i]);
    }

    while(q--){
        int k, u;
        cin >> k >> u;
        update(k-1, u);
        print(segTree[0][0]);
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