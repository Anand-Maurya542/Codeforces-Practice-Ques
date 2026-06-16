// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<char> Direction = {'R', 'L', 'D', 'U'};

void solve()
{
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    pair<int, int> start, end;
    queue<pair<int, int>> q;
    vector<vector<int>> monster_time(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                monster_time[i][j] = 0;
            }
        }
    }

    vector<vector<char>> prevDir(n, vector<char>(m));

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        // explore directions
        for (int d = 0; d < 4; d++)
        {
            int dx = dir[d].first + i;
            int dy = dir[d].second + j;

            if (dx < n && dx >= 0 && dy < m && dy >= 0 && grid[dx][dy] != '#' && monster_time[dx][dy] > 1 + monster_time[i][j])
            {

                monster_time[dx][dy] = 1 + monster_time[i][j];

                q.push({dx, dy});
            }
        }
    }

    // bfs from A
    vector<vector<int>> myTime(n, vector<int>(m, 0));
    q.push(start);

    bool escaped = false;

    while (!q.empty() && !escaped) 
    {
        auto [i, j] = q.front();
        q.pop();

        if(i==0 || i==n-1 || j==0 || j==m-1){
            end = {i,j};
            escaped = true;
            break;
        }

        // explore directions
        for (int d = 0; d < 4; d++)
        {
            int dx = dir[d].first + i;
            int dy = dir[d].second + j;

            if (dx < n && dx >= 0 && dy < m && dy >= 0 && grid[dx][dy] != '#' 
                && !visited[dx][dy] && monster_time[dx][dy] > 1 + myTime[i][j])
            {

                myTime[dx][dy] = 1 + myTime[i][j];
                visited[dx][dy]=true;
                prevDir[dx][dy] = Direction[d];

                q.push({dx, dy});
            }
        }
    }

    if(!escaped){
        cout<<"NO"<<"\n";
        return;
    }

    string path = "";

    pair<int, int> curr = end;

    while (curr != start)
    {
        char d = prevDir[curr.first][curr.second];
        path.push_back(d);

        int index = find(Direction.begin(), Direction.end(), d) - Direction.begin();

        curr.first -= dir[index].first;
        curr.second -= dir[index].second;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << '\n';
    cout << path.size() << '\n';
    cout << path << '\n';
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