#include<bits/stdc++.h>

using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define gcd(a, b) __gcd(a, b)

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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll binpow(ll b, ll n){ll result = 1; while (n > 0){ if (n & 1) result *= b; b *= b; n>>=1;} return result;}
bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; ++i) if (a % i == 0) return 0; return 1; }
void yes() { cout<< "YES\n"; }
void no() { cout<< "NO\n"; }

template <typename T> void read( vector<T>& v) { for (auto& x : v) cin >> x; }
template <typename T> void print( const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

void solve(){
    int n;
    cin>>n;
    bool p=false,c=false;

    if(n%2){
        if(prime(n-2)){
            yes();
            return;
        }
        else {
            no();
            return;
        }
    }
    else{
        for(int i = 2; i < n; i++){
        if(prime(i)){
            int x = n - i;

            if(x >= 2 && prime(x)) p = true;
            
            if(p) break;
        }
    }
        for(int i = 2; i < n; i++){
        if(prime(i)){
            int x = n - i;

            
            if(x > 1 && !prime(x)) c = true;

            if(c) break;
        }
    }

    if(p && c) yes();
    else no();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>> t;
    while( t--){
        solve();
    }
    return 0;
}

void solve(){
    ll n,k,t;
    cin>>n>>k>>t;
    ll f=(n*k*t)/100;
    int limit=f/k;
    int rem=f%k;
 
    vi ans;
    for(int i=0;i<limit;i++){
        ans.pb(k);
    }
    int s;
    if(rem>0){
        ans.pb(rem);
        s=n-limit-1;
    }
    else s=n-limit;
    for(int i=0;i<s;i++){
        ans.pb(0);
    }
    print(ans);
 
    
}





#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb(n) push_back(n)
#define eb(n) emplace_back(n)
#define fo(i,n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vpi vector<pair<ll,ll>>
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
#define set(x) unordered_set<x>
#define map(x, y) unordered_map<x, y>
#define MOD 1000000007
#define vin(v) for(auto &i:v)cin>>i
#define von(v) for(auto &i:v)cout<<i<<" "
#define debug(x) cout<<#x<<"="<<x<<endl
#define int long long

long long gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

//bool issquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int count_one(int n) {
    return __builtin_popcount(n);
}

int count_zero(int n) {
    return __builtin_clz(n);
}

// Power function for calculating a^b
long long power(long long a, long long b) {
    long long result = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// Modular Exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Sieve of Eratosthenes to find primes up to n
vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Check if a number is prime
bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Find minimum of three numbers
ll min3(ll a, ll b, ll c) {
    return min(a, min(b, c));
}

// Find maximum of three numbers
ll max3(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

// Binary Search to find the index of the element in sorted array
ll binary_search(const vi& arr, ll target) {
    ll left = 0, right = (ll)arr.size() - 1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Subarray Sum using prefix sum array
int subarray_sum(const vi& prefix, ll left, ll right) {
    if (left == 0) return prefix[right];
    return prefix[right] - prefix[left - 1];
}

// Prefix Sum Array
vi prefix_sum(const vi& arr) {
    ll n = arr.size();
    vi prefix(n);
    prefix[0] = arr[0];
    for (ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

// Find the median of an array
double median(vi& arr) {
    sort(arr.begin(), arr.end());
    ll n = arr.size();
    if (n % 2 == 1) return arr[n / 2];
    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}

// Calculate nCr (Combination) % MOD
long long nCr(int n, int r) {
    if (r > n) return 0;
    long long num = 1, denom = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        denom = (denom * (i + 1)) % MOD;
    }
    return (num * mod_exp(denom, MOD - 2, MOD)) % MOD;
}

// Factorial function modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T x) : data(x), next(nullptr) {}
    Node() : data(T()), next(nullptr) {}
    Node(T x, Node* next) : data(x), next(next) {}
};

template <typename T>
class DoublyNode {
public:
    T data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(T x) : data(x), next(nullptr), prev(nullptr) {}
    DoublyNode() : data(T()), next(nullptr), prev(nullptr) {}
    DoublyNode(T x, DoublyNode* next, DoublyNode* prev) : data(x), next(next), prev(prev) {}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    if(((n+1)&n)==0)yes;
    else no;
    
    return 0;
}