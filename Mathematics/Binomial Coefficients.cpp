// Manish Kumar, IIIT Allahabad

// https://cses.fi/problemset/task/1079

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

#define int long long

const int m = 1e9 + 7;

vector<int>v(1000001);

void pre(){
	v[0] = v[1] = 1;
	for(int i = 2; i < 1000001; i++)
		v[i] = i * v[i-1] % m;
}

int binExp(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int solve(){
	int n, a, b;
	cin >> n;
	while(n--){
		cin >> a >> b;
		int ans = 1;
		ans = v[a] * binExp(v[b], m-2) % m *binExp(v[a - b], m-2) % m;
		print(ans);
	}
	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;
	pre();
	while(t--) solve();
}
