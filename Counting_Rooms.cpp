// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int i, int j){
    visited[i][j]=true;

    for(auto& [x,y] : dir){
        int dx = x + i;
        int dy = y + j;
        if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]=='.' && !visited[dx][dy]){
            dfs(dx,dy);
        }
    }
}

void solve()
{
 cin >> n >> m;
 grid.assign(n, vector<char> (m));
 visited.assign(n, vector<bool>(m, false));
   for (int i = 0; i < n; i++){
       for (int j = 0; j < m; j++)
           cin >> grid[i][j];
    }
    int rooms=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='.' && !visited[i][j]){
                dfs(i,j);
                rooms++;
            }
        }
    }
    cout<<rooms<<'\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}