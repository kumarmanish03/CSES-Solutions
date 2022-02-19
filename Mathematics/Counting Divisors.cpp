// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/1713/

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

int N = 1e6+1;
vector<int> prime;

// counting no. of divisors
void pre(){
	prime.resize(N,2);
	for(int i = 2; i < N; i++){
			for(int j = i * i; j < N; j += i){
				if(j == i * i)
					prime[j] += 1; // For perfect sq
				else
					prime[j] += 2;
			}
	}
	prime[1] = 1;
	return;
}

int solve(){
	int n;
	cin >> n;

	cout << prime[n] << "\n";

	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre();
	int t = 1;
	cin>>t;
	while(t--) solve();
}
