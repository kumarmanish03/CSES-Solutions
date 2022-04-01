// Manish Kumar, IIIT Allahabad

// Refer:
// https://usaco.guide/problems/cses-2182-divisor-analysis/solution/
 
#include<bits/stdc++.h>
using namespace std;
 
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
 
#define int long long
 
const int m = 1e9+7;
 
int binExp(int a, int b, int m = 1e9+7){
	a %= m;
	int res = 1;
	while(b){
		if(b & 1){
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
 
int solve(){
	int n;
	cin >> n;
	int no = 1, sum = 1, prod = 1, xno = 1;
	vector<vector<int>> v(n, vector<int>(2));
	for(int i = 0; i < n; i++){
		cin >> v[i][0] >> v[i][1];
 
		no = no * (1 + v[i][1]) % m;
 
		sum = sum * ((binExp(v[i][0], v[i][1]+1) - 1) * binExp(v[i][0]-1, m-2) % m) % m;
 
		prod = binExp(prod, 1+v[i][1]) * binExp(binExp(v[i][0], v[i][1] * (1 + v[i][1]) / 2), xno) % m;
 
		xno = xno * (1 + v[i][1]) % (m-1);
	}
 
	print(no, sum, prod);
	
	return 0;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
	// cin>>t;
	while(t--) solve();
}
