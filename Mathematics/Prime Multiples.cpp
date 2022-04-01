// Manish Kumar, IIIT Allahabad

// https://cses.fi/problemset/task/2185

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

#define int long long

int solve(){
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int>v(k);
	for(int &x:v)
		cin >> x;

	for(int mask = 1; mask < (1 << k); mask++){
		int divisor = n;
		int cnt = 0;
		for(int j = 0; j < k; j++){
			if((1 << j) & mask){
				divisor /= v[j];
				cnt++;
			}
		}
		if(cnt % 2 == 1){
			ans += divisor;
		}
		else{
			ans -= divisor;
		}
	}
	
	print(ans);
	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;
	while(t--) solve();
}
