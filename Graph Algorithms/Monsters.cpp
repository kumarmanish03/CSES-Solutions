/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://cses.fi/problemset/result/3955774/
* @topic: Multisourcs BFS
* @desc: trick in this question is that, for same level you have to first move Monsters and that I managed using deque
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
char p[4] = {'U', 'D', 'L', 'R'};

char grid[1005][1005];
int parent[1005][1005];
int n, m;

bool isValid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool isBoundary(int i, int j){
    return (i == 0 || j == 0 || i == n-1 || j == m-1);
}

int solve(){
    cin >> n >> m;
    deque<vector<int>> q;
    int src_i=0, src_j=0, des_i=-1, des_j=-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M'){
                q.push_front({i, j, -1});
            }
            if(grid[i][j] == 'A'){
                q.push_back({i, j, 1});
                src_i = i;
                src_j = j;
            }
        }
    }
    deque<vector<int>> q_t;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto v = q.front();
            int i = v[0];
            int j = v[1];
            int t = v[2];
            q.pop_front();

            if(isBoundary(i, j) && t == 1){
                des_i = i;
                des_j = j;
            }

            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(!isValid(ni, nj) || grid[ni][nj] == '#' || grid[ni][nj] == 'M' || grid[ni][nj] == 'A')
                    continue;

                parent[ni][nj] = k;
                grid[ni][nj] = (t == 1) ? 'A' : 'M';
                if(t == 1)
                    q_t.push_back({ni, nj, 1});
                else
                    q_t.push_front({ni, nj, -1});
            }
        }
        q = q_t;
        q_t.clear();
    }

    if(des_i != -1){
        string path;
        print("YES");
        while(!(des_i == src_i && des_j == src_j)){
            int k = parent[des_i][des_j];
            path.push_back(p[k]);
            des_i = des_i - dx[k];
            des_j = des_j - dy[k];
        }
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