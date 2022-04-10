/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1650
* @methods: Method 1 : using sparse table, Method 2: using Segmente Trees
*
*/

// ===============================================================================================================================================

// Using Sparse Table

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
int sparse[N][25];

void construct(vector<int> &v){
    int n = v.size();
    memset(sparse, 0, sizeof(sparse));
    
    for(int i = 0; i < n; i++)
        sparse[i][0] = v[i];

    for(int j = 1; j < 25; j++){
        for(int i = 0; i + (1 << j) <= n; i++)
            sparse[i][j] = sparse[i][j-1] ^ sparse[i + (1<<(j-1))][j-1];
    }

    return;
}

int find(int l, int r){
    int res = 0;
    for(int j = 24; j >= 0; j--){
        if((1<<j) <= (r - l + 1)){
            res ^= sparse[l][j];
            l += (1<<j);
        }
    }
    return res;
}

int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    construct(v);

    while(q--){
        int a, b;
        cin >> a >> b;
        print(find(a-1, b-1));
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

// ===============================================================================================================================================

// Using Segmented Trees

/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1649
* @logic: Segment Tree, notice the change in segment Tree
* @refer: https://cp-algorithms.com/data_structures/segment_tree.html
*
*/
 
#include<bits/stdc++.h>
using namespace std;
 
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define print_(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
#define fs  first
#define sc  second
#define pb  push_back
#define int long long
 
const int N = 2e5+1;
int segTree[4*N];
 
int construct(vector<int> &arr, int node, int sl, int sr){
    if(sl == sr){
        segTree[node] = arr[sl];
        return segTree[node];
    }
 
    int mid = sl + (sr - sl) / 2;
    segTree[node] = construct(arr, 2*mid+1, sl, mid) ^ construct(arr, 2*mid+2, mid+1, sr);
    return segTree[node];
}
 
int getXor(int node, int sl, int sr, int l, int r){
    if(l <= sl && sr <= r)
        return segTree[node];
 
    if(sr < l || r < sl)
        return 0;
 
    int mid = sl + (sr - sl) / 2;
    return (getXor(2*mid+1, sl, mid, l , r) ^ getXor(2*mid+2, mid+1, sr, l, r));
}
 
int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    
    construct(v, 0, 0, n-1);
 
    int type;
    while(q--){
        {
            int a, b;
            cin >> a >> b;
            int mn = getXor(0, 0, n-1, a-1, b-1);
            print(mn);
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
