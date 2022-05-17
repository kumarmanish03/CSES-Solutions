/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/task/1193/
* @TC: O(n*m)
* @desc: Trick in this question is we have to keep track of previous Step.
*  # It's like storing the parent of each child
*
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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char p[4] = {'L', 'R', 'U', 'D'};

bool isValid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, vector<vector<int>>& prevStep){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!isValid(ni, nj, n, m) || grid[ni][nj] == '#' || vis[ni][nj] == true)
                continue;
            q.push({ni, nj});
            vis[ni][nj] = true;
            prevStep[ni][nj] = k;

            if(grid[ni][nj] == 'B'){
                return true;
            }
        }
    }

    return false;
}

int solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> prevStep(n, vector<int>(m, -1));

    int src_i = 0, src_j = 0;
    int des_i = 0, des_j = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                src_i = i;
                src_j = j;
            }
            if(grid[i][j] == 'B'){
                des_i = i;
                des_j = j;
            }
        }
    }
    
    if(bfs(src_i, src_j, grid, vis, prevStep)){
        string path;

        while(des_i != src_i || des_j != src_j){
            int pos = prevStep[des_i][des_j];
            path.push_back(p[pos]);
            des_i = des_i - dx[pos];
            des_j = des_j - dy[pos];
        }

        print("YES");
        reverse(path.begin(), path.end());
        print(path.size());
        print(path);
    }
    else{
        print("NO");
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    
    for(int i = 0; i < t; i++)
        solve();
}