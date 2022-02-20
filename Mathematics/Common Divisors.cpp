// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/1081/

// Idea:
// Given a value, x, we can check whether a pair has a GCD equal to x by checking
// all the multiples of x. With that information, loop through all
// possible values of and check if it is a divisor to two or more values

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define printArr(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

// #define int long long

// ===============================================================


int solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> freq(1e6+1, 0);
	for(int &x:v){
		cin >> x;
		freq[x]++;
	}

	for(int gcd = 1e6; gcd > 0; gcd--){
		int div = 0;
		for(int j = gcd; j < 1e6+1; j += gcd)
			div += freq[j];

		if(div >= 2){
			cout << gcd;
			break;
		}
	}

	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;
	while(t--) solve();
}
