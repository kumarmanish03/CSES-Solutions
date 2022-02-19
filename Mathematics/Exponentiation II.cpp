// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/1712/
 
#include<bits/stdc++.h>
using namespace std;
 
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define printArr(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
 
#define int long long
 
// ===============================================================
 
int M = 1e9+7;
 
int solve(){
	int a, b, c;
	cin >> a >> b >> c;
 
	int res1 = 1;
	M--;
	while(c){
		if(c&1)
			res1 = (res1 % M * b % M) % M;
		b = (b % M * b % M) % M;	
		c = c >> 1;
	}
 
	int res2 = 1;
	M++;
	while(res1){
		if(res1&1)
			res2 = (res2 % M * a % M) % M;
		a = (a % M * a % M) % M;
		res1 = res1 >> 1;
	}
 
	cout << res2 << "\n";
 
	return 0;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
	cin>>t;
	while(t--) solve();
}
