/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1192/
* @desc: Easy DFS
* @TC: O(nm)
*
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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    for(int k = 0; k < 4; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(!isValid(ni, nj, n, m) || grid[ni][nj] == '#')
            continue;
        grid[ni][nj] = '#';
        dfs(ni, nj, grid);
    }
}

int solve(){
    int n, m, rooms = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                rooms++;
                dfs(i, j, grid);
                grid[i][j] = '#';
            }
        }
    }

    cout << rooms;
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}