// Manish Kumar, IIIT Allahabad

https://cses.fi/problemset/task/2189

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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int temp1 = (y2-y1)*(x3-x2) - (y3-y2)*(x2-x1);

    if(temp1 == 0){
        print("TOUCH");
        return 0;
    }

    if(temp1 > 0){
        print("RIGHT");
    }
    else{
        print("LEFT");
    }
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--) solve();
}
