/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1076/
* @refer: https://usaco.guide/problems/cses-1076-sliding-median/solution
* see 2 Solutions
*/

// Solution 1 [using two multisets]

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

long N, M;
long arr[200010];

multiset<long> up;
multiset<long> low;

void ins(long val){ // insert val into sets
	long a = *low.rbegin(); // current median
	if(a < val){
		up.insert(val);
		if(up.size() > M/2){
			low.insert(*up.begin());
			up.erase(up.find(*up.begin()));
		}
	}
	else{
		low.insert(val);
		if(low.size() > (M + 1)/2){
			up.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
}


void er(long val){ // erase from sets

	if(up.find(val) != up.end()) up.erase(up.find(val));

	else low.erase(low.find(val));

	if(low.size() < up.size()){
		low.insert(*up.begin());
		up.erase(up.begin());
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> arr[i];
	low.insert(arr[0]); for(int i = 1; i < M; i++) ins(arr[i]);
	cout << *low.rbegin() << " ";
	for(long i = M; i < N; i++){
		if(M == 1){
			ins(arr[i]);
			er(arr[i - M]);
		}
		else{
			er(arr[i - M]);
			ins(arr[i]);
		}
		cout << *low.rbegin() << " ";
	}
	cout << endl;
}

// Soultion 2 [using ordered_set]

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>


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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);

  ordered_set oset;
  int t = 0;
  for (int i = 0; i < n; i++){

    int u; cin >> u; a[i] = u;

    // used t to handle duplicates
    oset.insert({u, t++});

    if (i >= k){
      // used lower_bound to handle duplicates 
      // it always delete element of value a[i-k] for which 't' may be anything) 
      oset.erase(oset.lower_bound({a[i - k], 0}));
    }

    if (i >= k - 1){
      cout << (*oset.find_by_order((k - 1) / 2)).first << " ";
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