/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1137/
* @TC: O(n * sqrt(n))
* @topic: Euler tour / flatting tree, Mo algorithm and coordinate compression
* @refer: see subtree queries
* @desc:
*  # since queries are offline, hence we can apply mo's algorithm
*  # dfs(): first we flatted the tree, this is very helpful becoz tree is now converted into a liner data structure
*  # coordinate_compression(): we apply coordinate compression as values is in range 1e9
*  # mo_algo(): then we applied mo_algorithm that will calculate all ranges answer in O(n*sqrt(n)) 
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
vector<int> color(N, 0);
vector<int> start1(N, 0);
vector<int> end1(N, 0);
vector<int> flat_tree(N, 0);
vector<int> ans(N+1, 0);
int timer;
int n;

// flatting the tree 
void dfs(int u, int p){
    start1[u] = ++timer;
    flat_tree[timer] = color[u];
    for(int v: tree[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    end1[u] = timer;
}

struct Q{
    int i, l, r;
};

void coordinate_compression(){
    map<int, int> m;
    for(int i = 1; i <= n; i++){
        m[color[i]];
    }
    int ind = 1;
    for(auto &i:m){
        i.second = ind++;
    }
    for(int i = 1; i<= n; i++){
        color[i] = m[color[i]];
    }
}

void mo_algo() {
    int len = sqrtl(n);
    
    Q qry[n+1];
    for(int u = 1; u <= n; u++){
        qry[u].i = u;
        qry[u].l = start1[u];
        qry[u].r = end1[u];
    }

    // for(int i = 1; i <= n; i++){
    //     map<int, int> m;
    //     for(int j = qry[i].l; j <= qry[i].r; j++){
    //         m[flat_tree[j]];
    //     }
    //     ans[qry[i].i] = m.size();
    // }

    sort(qry+1, qry+n+1, [=](Q a, Q b){
        if(a.l / len == b.l / len)
            return a.r > b.r;
        return a.l < b.l;
    });

    int curr_l = 1, curr_r = 0, l, r, curr_ans = 0;
    vector<int> freq(2e5+5, 0);

    for(int i = 1; i <= n; i++){
        l = qry[i].l;
        r = qry[i].r;

        while(curr_r < r){
            curr_r++;
            freq[flat_tree[curr_r]]++;
            if(freq[flat_tree[curr_r]] == 1)
                curr_ans++;
        }

        while(l < curr_l){
            curr_l--;
            freq[flat_tree[curr_l]]++;
            if(freq[flat_tree[curr_l]] == 1)
                curr_ans++;
        }

        while(r < curr_r){
            freq[flat_tree[curr_r]]--;
            if(freq[flat_tree[curr_r]] == 0)
                curr_ans--;
            curr_r--;
        }

        while(curr_l < l){
            freq[flat_tree[curr_l]]--;
            if(freq[flat_tree[curr_l]] == 0)
                curr_ans--;
            curr_l++;
        }

        ans[qry[i].i] = curr_ans;
    }

}

int solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> color[i];

    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    coordinate_compression();

    timer = 0;
    dfs(1, -1);

    mo_algo();

    for(int u = 1; u <= n; u++){
        cout << ans[u] << " ";
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