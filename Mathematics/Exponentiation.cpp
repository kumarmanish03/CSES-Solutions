// Manish Kumar, IIIT Allahabad
 
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
 
const int M = 1e9+7;
 
int solve(){
	int a, b;
	cin >> a >> b;
	int res = 1;
	while(b){
		if(b&1)
			res = (res % M * a % M) % M;
		a = (a % M * a % M) % M;
		b = b >> 1;
	}
 
	cout << res << "\n";
 
	return 0;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
	cin>>t;
	while(t--) solve();
}