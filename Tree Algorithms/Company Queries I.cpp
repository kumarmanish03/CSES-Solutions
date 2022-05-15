/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1687
* @refer: https://www.youtube.com/watch?v=FAfSArGC8KY&ab_channel=KartikArora
* @topic: binary lifting \ binary uplifting, tree with dp
* @TC: O(nlogn)
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

const int N = 2e5+5;
vector<int> tree[N];
// up[i][j]: stores 2^j(th) ancestor of i node
int up[N][20];

void binary_lifting(int u, int p=-1){

    up[u][0] = p;
    for(int k = 1; k < 20; k++){
        if(up[u][k-1] != -1){
            up[u][k] = up[up[u][k-1]][k-1];
        }
        else{
            up[u][k] = -1;
        }
    }

    for(int v: tree[u]){
        if(v == p) continue;
        binary_lifting(v, u);
    }
}

// tells 2^k (th) ancestor of node u
int ancestor(int u, int k){
    if(u == -1 || k == 0){
        return u;
    }

    for(int i = 19; i >= 0; i--){
        if(k >= (1 << i)){
            return ancestor(up[u][i], k - (1 << i));
        }
    }

    return -1; // control will never reach here
}

int solve(){
    int n, q;
    cin >> n >> q;
    int a;
    for(int i = 0; i < n-1; i++){
        cin >> a;
        tree[a].push_back(i+2);
        tree[i+2].push_back(a);
    }

    binary_lifting(1, -1);

    while(q--){
        int u, k;
        cin >> u >> k;
        cout << ancestor(u, k) << "\n";
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