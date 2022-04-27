/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1651/
* @TC: O(qlogn)
* @desc: Using Difference array
* @Solution 1: using Fenwick Tree
* @Solution 2: using Segment Tree
*
*/

/* Solution 1 */

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

const int N = 2e5;
// bit array should be 1 based indexed
vector<int> bit(N+1, 0);

// return sum of i elements
int sum(int i){
    int ans = 0;
    for(; i > 0; i-=(i & -i)){
        ans += bit[i];
    }
    return ans;
}

// add x in ith index
void update(int i, int val){
    for(; i<=N; i+=(i&-i)){
        bit[i] += val;
    }
}

int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1, 0);
    for(int i = 1; i < n+1; i++){
        cin >> v[i];
    }

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, val;
            cin >> l >> r >> val;
            update(l, val);
            update(r+1, -val);
        }
        else{
            int i;
            cin >> i;
            int ans = sum(i) + v[i];
            print(ans);
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


/* Soultion 2 */

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
int segTree[4 * N];
 
// TC: O(n)
int construct(vector<int> &arr, int node, int sl, int sr){
    if(sl == sr){
        segTree[node] = arr[sl];
        return segTree[node];
    }
 
    int mid = sl + (sr - sl) / 2;
    segTree[node] = construct(arr, 2*mid+1, sl, mid) + construct(arr, 2*mid+2, mid+1, sr);
    return segTree[node];
}
 
// TC: O(logn)
int getSum(vector<int> &arr, int node, int sl, int sr, int l, int r){
    // Total Overlap
    if(l <= sl && sr <= r)
        return segTree[node];
    // No Overlap
    if(sl > r || sr < l)
        return 0;
 
    // Partial Overlap
    int mid = sl + (sr - sl) / 2;
    return getSum(arr, 2*mid+1, sl, mid, l, r) + getSum(arr, 2*mid+2, mid+1, sr, l, r);
}
 
// TC: O(logn)
void update(vector<int> &arr, int node, int sl, int sr, int pos, int diff){
    if(pos < sl || sr < pos)
        return;
 
    segTree[node] += diff;
    if(sl != sr){
        int mid = sl + (sr - sl) / 2;
        update(arr, 2*mid+1, sl, mid, pos, diff);
        update(arr, 2*mid+2, mid+1, sr, pos, diff);
    }
}
 
int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n), diff(n, 0);
    for(int &x:v)
        cin >> x;
    
    construct(diff, 0, 0, n-1);
    int type;
    while(q--){
        cin >> type;
        if(type == 1){
            int a, b, u;
            cin >> a >> b >> u;
            update(v, 0, 0, n-1, a-1, u);
            update(v, 0, 0, n-1, b, -u);
        }
        else{
            int k;
            cin >> k;
            int sum = v[k-1] + getSum(diff, 0, 0, n-1, 0, k-1);
            print(sum);
        }
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