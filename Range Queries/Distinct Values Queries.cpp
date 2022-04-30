/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1734/
* @topics: MO's algorithm, corrdinate compression
* @refer: [logic] https://codeforces.com/blog/entry/77128
*   [Mo's algo] https://www.youtube.com/watch?v=0Cu9Kg7RJYg&t=851s&ab_channel=ApnaCollege
*   [corrdinate compression] https://www.youtube.com/watch?v=s9oXy-fZUzg&ab_channel=Luv
*
* @TC: O((n+q)root(n))
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

struct Q {
    int i, l, r;
};

int solve(){
    int n, query;
    cin >> n >> query;
    vector<int> v(n), v1;
    for(int &x:v)
        cin >> x;

    /* corrdinate compression */
    v1 = v;
    sort(v1.begin(), v1.end());
    map<int, int> compress;
    int ind = 1;
    for(auto a: v1){
        if(!compress[a])
            compress[a] = ind++;
    }
    for(int &a:v)
        a = compress[a];
    /* ********************** */ 


    int len = sqrtl(n);

    vector<int> ans(query, 0);
    Q q[n];
    for(int i = 0; i < query; i++){
        int l, r;
        cin >> l >> r;
        q[i].l = l-1;
        q[i].r = r-1;
        q[i].i = i;
    }

    sort(q, q + query, [=](Q a, Q b){
        if(a.l / len == b.l / len)
            return a.r > b.r;
        return a.l / len < b.l / len;
    });

    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    // frequency count array
    vector<int> m(2e5+5, 0);

    for(int i = 0; i < query; i++){
        l = q[i].l;
        r = q[i].r;

        while(curr_r < r){
            curr_r++;
            m[v[curr_r]]++;
            if(m[v[curr_r]] == 1)
                curr_ans++;
        }

        while(l < curr_l){
            curr_l--;
            m[v[curr_l]]++;
            if(m[v[curr_l]] == 1)
                curr_ans++;
        }

        while(r < curr_r){
            m[v[curr_r]]--;
            if(m[v[curr_r]] == 0)
                curr_ans--;
            curr_r--;
        }

        while(l > curr_l){
            m[v[curr_l]]--;
            if(m[v[curr_l]] == 0)
                curr_ans--;
            curr_l++;
        }

        ans[q[i].i] = curr_ans;
    }

    for(int a:ans)
        print(a);

    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}