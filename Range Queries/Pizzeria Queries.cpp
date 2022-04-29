/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2206
* @refer: https://usaco.guide/problems/cses-2206-pizzeria-queries/solution
* @desc: using two segment trees, [for more see above link]
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
// {sum, max prefix sum}
int segLeft[4*N], segRight[4*N];
int n;

void updateLeft(int pos, int val, int node = 0, int sl = 0, int sr = n-1){
    if(pos < sl || sr < pos)
        return;

    if(sl == sr){
        segLeft[node] = val - (pos + 1);
    }
    else{
        int mid = (sl + sr) / 2;
        updateLeft(pos, val, 2*mid+1, sl, mid);
        updateLeft(pos, val, 2*mid+2, mid+1, sr);
        segLeft[node] = min(segLeft[2*mid+1], segLeft[2*mid+2]);
    }
}

int findLeft(int l, int r, int node = 0, int sl = 0, int sr = n-1){
    if(r < sl || sr < l){
        return LLONG_MAX;
    }

    if(l <= sl && sr <= r){
        return segLeft[node];
    }

    int mid = (sl + sr) / 2;
    return min(findLeft(l, r, 2*mid+1, sl, mid), findLeft(l, r, 2*mid+2, mid+1, sr));
}

void updateRight(int pos, int val, int node = 0, int sl = 0, int sr = n-1){
    if(pos < sl || sr < pos)
        return;

    if(sl == sr){
        segRight[node] = val + (pos + 1);
    }
    else{
        int mid = (sl + sr) / 2;
        updateRight(pos, val, 2*mid+1, sl, mid);
        updateRight(pos, val, 2*mid+2, mid+1, sr);
        segRight[node] = min(segRight[2*mid+1], segRight[2*mid+2]);
    }
}

int findRight(int l, int r, int node = 0, int sl = 0, int sr = n-1){
    if(r < sl || sr < l){
        return LLONG_MAX;
    }

    if(l <= sl && sr <= r){
        return segRight[node];
    }

    int mid = (sl + sr) / 2;
    return min(findRight(l, r, 2*mid+1, sl, mid), findRight(l, r, 2*mid+2, mid+1, sr));
}

int solve(){
    int q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        updateLeft(i, v[i]);
        updateRight(i, v[i]);
    }
    
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k, u;
            cin >> k >> u;
            updateLeft(k-1, u);
            updateRight(k-1, u);
        }
        else{
            int k;
            cin >> k;
            int left = findLeft(0, k-1) + k;
            int right = findRight(k-1, n-1) - k;
            print(min(left, right));
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