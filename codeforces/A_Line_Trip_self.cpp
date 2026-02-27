/*
author: Anand Kumar Maurya
description: MCA I year, NIT Allahabad.
*/
#include <bits/stdc++.h>
using namespace std;
/* ---------- Macros ---------- */
#define sza(x) ((int)(x).size())
#define all(a) (a).begin(), (a).end()
#define minV(a) *min_element(all(a))
#define maxV(a) *max_element(all(a))
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define gcd(a, b) __gcd(a, b)
#define pq priority_queue

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
using pqq =priority_queue<int,vi,greater<int>>;
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

ll mod_exp(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

ll binpow(ll b, ll n) {
    ll result = 1;
    while (n > 0) {
        if (n & 1) result *= b;
        b *= b;
        n >>= 1;
    }
    return result;
}

bool prime(ll a) {
    if (a <= 1) return false;
    for (ll i = 2; i * i <= a; ++i)
        if (a % i == 0) return false;
    return true;
}

/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }

/* ---------- IO Helpers ---------- */
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

vector<int> nextSmallerRightIndex(vector<int>& arr) {    int n = arr.size();    vector<int> nsr(n, -1);   stack<int> st;      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nsr[i] = st.top();
        }

        st.push(i);
    }
    return nsr;
}
vector<int> nextSmallerLeftIndex(vector<int>& arr) {   int n = arr.size();    vector<int> nsl(n, -1);    stack<int> st;      for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nsl[i] = st.top();
        }

        st.push(i);
    }
    return nsl;
}
vector<int> nextGreaterLeftIndex(vector<int>& arr) {    int n = arr.size();    vector<int> ngl(n, -1);    stack<int> st;     for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ngl[i] = st.top();
        }

        st.push(i);
    }
    return ngl;
}
vector<int> nextGreaterRightIndex(vector<int>& arr) {    int n = arr.size();    vector<int> ngr(n, -1);    stack<int> st;      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ngr[i] = st.top();
        }

        st.push(i);
    }
    return ngr;
}
//for(int i=0;i<n;i++){}
template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

/* ---------- Solve ---------- */
void solve() {
   ll n,x;cin>>n>>x;
   vll a(n);
   read(a);
   vll diff;
   diff.pb(a[0]);
   for(int i=1;i<n;i++){
    diff.pb(a[i]-a[i-1]);
   }
   diff.pb((x-a[n-1])*2);

   cout<<maxV(diff)<<"\n";
    
}

/* ---------- Main ---------- */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}