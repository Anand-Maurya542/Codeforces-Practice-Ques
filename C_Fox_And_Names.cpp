/**
author: Vineet Sikarwar
description: MCA I year, NIT Allahabad.
name_art:
██╗   ██╗██╗███╗   ██╗███████╗███████╗████████╗
██║   ██║██║████╗  ██║██╔════╝██╔════╝╚══██╔══╝
██║   ██║██║██╔██╗ ██║█████╗  █████╗     ██║
╚██╗ ██╔╝██║██║╚██╗██║██╔══╝  ██╔══╝     ██║
 ╚████╔╝ ██║██║ ╚████║███████╗███████╗   ██║
  ╚═══╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝   ╚═╝

███████╗██╗██╗  ██╗ █████╗ ██████╗ ██╗    ██╗ █████╗ ██████╗
██╔════╝██║██║ ██╔╝██╔══██╗██╔══██╗██║    ██║██╔══██╗██╔══██╗
███████╗██║█████╔╝ ███████║██████╔╝██║ █╗ ██║███████║██████╔╝
╚════██║██║██╔═██╗ ██╔══██║██╔══██╗██║███╗██║██╔══██║██╔══██╗
███████║██║██║  ██╗██║  ██║██║  ██║╚███╔███╔╝██║  ██║██║  ██║
╚══════╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝
*/
#include <bits/stdc++.h>
using namespace std;

/* ---------- Macros ---------- */
#define sza(x) ((int)(x).size())
#define all(a) (a).begin(), (a).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define gcd(a, b) __gcd(a, b)

/* ---------- Types ---------- */
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vc = vector<char>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using umsi = unordered_map<string, int>;
using si = set<int>;
using sc = set<char>;

/* ---------- Constants ---------- */
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

/* ---------- Math Utilities ---------- */
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }

ll mod_exp(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

ll binpow(ll b, ll n)
{
    ll result = 1;
    while (n > 0)
    {
        if (n & 1)
            result *= b;
        b *= b;
        n >>= 1;
    }
    return result;
}

bool prime(ll a)
{
    if (a <= 1)
        return false;
    for (ll i = 2; i * i <= a; ++i)
        if (a % i == 0)
            return false;
    return true;
}

/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }

/* ---------- IO Helpers ---------- */
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

/* ---------- Solve ---------- */
void solve()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto &w : words)
        cin >> w;

    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);

    for (int i = 1; i < n; i++)
    {
        string a = words[i - 1];
        string b = words[i];

        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++)
        {
            if (a[j] != b[j])
            {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                bool exists = false;
                for (int x : adj[u])
                {
                    if (x == v)
                    {
                        exists = true;
                        break;
                    }
                }

                if (!exists)
                {
                    adj[u].push_back(v);
                    indeg[v]++;
                }

                found = true;
                break;
            }
        }
        if (!found && a.size() > b.size())
        {
            cout << "Impossible\n";
            return;
        }
    }

    // Topo sort
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    string ans = "";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans += (char)(u + 'a');

        for (auto v : adj[u])
        {
            if (--indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (ans.size() < 26)
    {
        cout << "Impossible\n";
        return;
    }

    cout << ans << "\n";
}
/* ---------- Main ---------- */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}