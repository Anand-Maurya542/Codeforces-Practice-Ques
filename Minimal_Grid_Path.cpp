// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
int n;
vector<vector<char>> grid;



void solve()
{
    cin >> n ;
    grid.assign(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        cin>>grid[i][j];


    }
    
    string ans;

    vector<pair<int,int>> curr ; //{i,j} -> curr cell;
    curr.push_back({0,0});
    vector<vector<int>> visited(n, vector<int>(n,0));
    visited[0][0]=1;

    //ans length = 2n-1

    //har step pe ek character lenge -> smallest wala

    ans.push_back(grid[0][0]);

    for(int step = 1; step < 2*n-1; step++){
        char best = 'Z';

        for(auto[x,y] : curr){
            if(x+1 < n) best = min(best, grid[x+1][y]);
            if(y+1 < n) best = min(best, grid[x][y+1]);
        }

        ans.push_back(best);

        vector<pair<int, int>> next; //next cell to jump from current cell

        for(auto [x,y] : curr){
            if(x+1 < n && grid[x+1][y]==best && !visited[x+1][y]){
                visited[x+1][y]=1;
                next.push_back({x+1, y});
            }
            if(y+1 < n && grid[x][y+1]==best && !visited[x][y+1]){
                visited[x][y+1]=1;
                next.push_back({x, y+1});
            }

        }

        curr = next;

    }
    cout<<ans<<'\n';

    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}