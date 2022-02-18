// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/1755/
 
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
	string s;
	cin >> s;
	int n = s.size();
	int arr[26];
	memset(arr, 0, sizeof(arr));
 
	for(char c:s)
		arr[c - 'A']++;
 
	int odd = 0;
	for(int i:arr)
		if(i&1) odd++;
 
	if(!(((odd == 1) && n&1) || ((odd==0) && !(n&1)))){
		print("NO SOLUTION");
	}
	else{
		string ans = s;
		int l = 0, r = n-1;
		for(int i = 0; i < 26; i++){
			if(arr[i]&1){
				ans[n/2] = char(i + 'A');
				arr[i]--;
				i--;
			}
			else{
				while(arr[i]){
					ans[l++] = ans[r--] = char(i + 'A');
					arr[i] -= 2;
				}
			}
		}
		print(ans);
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
