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
        const ll INF = 1e18;
      
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

            }

            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
            pq.push({0, 1}); //,wt,node;

            vector<vector<ll>> dp(n+1, vector<ll>(4, INF));
            dp[1][0]=0; //cost
            dp[1][1]=1; //ways
            dp[1][2]=0; //min edges
            dp[1][3]=0 ;//max edges


            while (!pq.empty())
            {
                auto [wt, u] = pq.top();
                pq.pop();
                if (wt > dp[u][0])
                    continue;

                for (auto &[v, next_wt] : adj[u])
                {
                    if (dp[u][0] + next_wt < dp[v][0])
                    {
                        dp[v][0] = dp[u][0] + next_wt;
                        dp[v][1] = dp[u][1];
                        dp[v][2] = dp[u][2] +1;
                        dp[v][3] = dp[u][3] + 1;


                        pq.push({dp[v][0],v});
                    }else if(dp[u][0] + next_wt == dp[v][0]){
                        dp[v][1] = (dp[v][1] + dp[u][1]) % MOD;
                        dp[v][2] = min(dp[v][2], dp[u][2] +1);
                        dp[v][3] = max(dp[v][3], dp[u][3] + 1);
                    }
                }
            }
            
            cout<<dp[n][0]<<' '<<dp[n][1]<< ' '<<dp[n][2]<<' '<<dp[n][3]<<'\n';

          
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