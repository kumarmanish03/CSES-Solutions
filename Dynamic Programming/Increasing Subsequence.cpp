/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1145/
* @desc: LIS in O(nlogn) using Binary Search 
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

int solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;

    int lis = 0;
    vector<int> temp;
    for(int i = 0; i < n; i++){
        // element greater or equal to v[i]
        auto it = lower_bound(temp.begin(),temp.end(), v[i]);
        // if v[i] is greatest from all elements in temp than 'LIS' increases 
        if(it == temp.end()){
            temp.push_back(v[i]);
            lis++;
        }
        // else change it to v[i] (for better subsequence, as value decreases)
        else{
            *it = v[i];
        }
    }
    
    print(lis);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}