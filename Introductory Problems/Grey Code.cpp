// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/2205/

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

int solve(){
	int n;
	cin >> n;
	vector<string> v(1 << n);

	for(int i = 1; i <= n; i++){
		int k = 1<<i;
		int kk = 0;
		bool flag = 1;
		for(int j = 0; j < (1<<n); j++){
			if(j < (1<<(i-1)))
				v[j].push_back('0');
			else{
				if(flag)
					v[j].push_back('1'), kk++;
				else
					v[j].push_back('0'), kk--;
				if(kk == k || kk == 0) flag = !flag;
			}
		}
	}

	for(string s:v)
		cout << s << "\n";
	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;
	while(t--) solve();
}
