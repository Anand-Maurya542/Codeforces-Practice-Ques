        // Author: Anand Maurya , MNNIT ALLAHABAD

        #include <bits/stdc++.h>
        using namespace std;
        #define all(a) (a).begin(), (a).end()
        /* ---------- Output Helpers ---------- */
        inline void yes() { cout << "YES\n"; }
        inline void no() { cout << "NO\n"; }
        template <typename T>
        void read(vector<T> &v)
        {
            for (auto &x : v)
                cin >> x;
        }

        template <typename T>
        void print(const vector<T> &v)
        {
            for (const auto &x : v)
                cout << x << ' ';
            cout << '\n';
        }

        // #define int long long

        using ll = long long;
        const int MOD = 1e9 + 7;
        const long long INF = 1e18;
        // vector<vector<int>>dp;
        // vector<int>dp;
        // dp.assign(n, vector<int>(m, -1));
        // dp.assign(n, -1);
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // vector<vector<int>> adj(n);
        void solve()
        {
            int n, k;
            cin >> n >> k;
            vector<vector<pair<int, int>>> adj(n + 1);
            for (int i = 0; i < k; i++)
            {
                int u, v, wt;
                cin >> u >> v >> wt;
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }

            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
            pq.push({0, 1}); //,wt,node;
            vector<ll> dist(n + 1, INF);
            vector<int> parent(n + 1,-1);
            parent[1] = -1;
            dist[1] = 0;
            while (!pq.empty())
            {
                auto [wt, node] = pq.top();
                pq.pop();
                if (wt > dist[node])
                    continue;

                for (auto &[next, next_wt] : adj[node])
                {
                    if (dist[node] + next_wt < dist[next])
                    {
                        dist[next] = dist[node] + next_wt;
                        parent[next] = node;
                        pq.push({dist[next],next});
                    }
                }
            }

            if (dist[n] == INF)
            {
                cout << -1 << '\n';
                return;
            }
            vector<int> path;
            int node = n;
            

            while (node != -1)
            {
                
                path.push_back(node);
                node = parent[node];
            }

            reverse(path.begin(), path.end());
            print(path);
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