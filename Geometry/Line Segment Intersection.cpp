/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/2190/
* @refer: https://cses.fi/problemset/task/2190/
*
* @hint: using orientation 
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
#define fs  first
#define sc  second
#define pb  push_back
#define int long long

int orient(int x, int y, int x1, int y1, int x2, int y2){
    int val = 0;
    int temp = (y2 - y1) * (x - x2) - (y - y2) * (x2 - x1);
    if(temp == 0)
        return val;

    val = (temp > 0) ? -1 : 1;
    return val;
}

bool onSegment(int x, int y, int x1, int y1, int x2, int y2){
    if(((x1 <= x && x <= x2) && (y1 <= y && y <= y2)) || ((x1 >= x && x >= x2) && (y1 >= y && y >= y2)))
        return true;
    return false;
}

int solve(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int t1 = orient(x3, y3, x1, y1, x2, y2);
    int t2 = orient(x4, y4, x1, y1, x2, y2);
    int t3 = orient(x1, y1, x3, y3, x4, y4);
    int t4 = orient(x2, y2, x3, y3, x4, y4);

    if((t1 != t2) && (t3 != t4)){
        print("YES");
    }
    else if(t1 == 0 && onSegment(x2, y2, x3, y3, x4, y4)){
        print("YES");
    }
    else if(t2 == 0 && onSegment(x2, y2, x3, y3, x4, y4)){
        print("YES");
    }
    else if(t3 == 0 && onSegment(x4, y4, x1, y1, x2, y2)){
        print("YES");
    }
    else if(t4 == 0 && onSegment(x4, y4, x1, y1, x2, y2)){
        print("YES");
    }
    else
        print("NO");

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin>>t;
    for(int i = 0; i < t; i++)
        solve();
}
