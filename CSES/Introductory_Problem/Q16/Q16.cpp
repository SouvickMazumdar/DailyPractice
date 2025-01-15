// Owner :- Souvick Mazumdar..
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll            long long int
#define ld              long double
#define ull             unsigned long long
#define INF             9223372036854775807
#define ff              first
#define ss              second
#define MOD             1000000007
#define MAX             100005
#define pb              push_back
#define no              cout<<"NO\n"
#define yes             cout<<"YES\n"
#define sz(x)           x.size();
#define all(x)          x.begin(), x.end()
#define allrev(x)       x.rbegin(), x.rend()
#define pi              pair<ll,ll>
#define vi              vector<ll>
#define vpi             vector<pi>
#define vvi             vector<vector<ll>>
#define vvpi            vector<vector<pi>>
#define umii            unordered_map<ll,ll>
#define endl           "\n"
#define PI              3.141592653589793238462
#define set_bits        __builtin_popcountll
#define FOR(i,a,b)      for(ll i=a; i<b; ++i)
#define FORE(i,b)        for(auto i : b)
#define FORRev(i,a,b)   for(ll i=a; i>=b; --i)
#define precision(n)    cout<<setprecision(n)<<fixed;
// typedef tree<pi , null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> PBDS; //find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(bool t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue<T> pq) { cerr << "[ "; while (!pq.empty()) { cerr << pq.top() << " "; pq.pop(); } cerr << " ]"; }
template <class T> void _print(priority_queue<T, vector<T>, greater<T>> pq) { cerr << "[ "; while (!pq.empty()) { cerr << pq.top() << " "; pq.pop(); } cerr << " ]"; }

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//-------------------------------------------------------------------------------------------

int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
bool isSorted(const vi &a) { int n = sz(a); FOR(i, 1, n) { if (a[i - 1] > a[i]) return false;} return true;}
int binpowerMOD(int x, int y, int p) { int res = 1; x = x % p; if (x == 0) return 0; while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1; x = (x * x) % p;} return res;}
int floor1(int n, int k) {if (n % k == 0 || n >= 0)return n / k; return (n / k) - 1;}
int ceil1(int n, int k) {return floor1(n + k - 1, k);}
int binpow(int a, int b) { int res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
int lcm (int a, int b) { return a / __gcd(a, b) * b;}
bool many_test = 0;
//----- The Minute you think of giving up, think of the reason why you held so long..!! ------
/*
Problem Name: Apple Division
Problem Link: https://cses.fi/problemset/task/1623
Approach : 
*/
ll tot=0;
// ll mini=INF;

// void rec(vector<ll>&vc,int ind, ll presm)
// {
//     if(ind==-1)
//     {
//         mini=min(mini, abs(tot-2*presm));
//         return;
//     }
//     rec(vc,ind-1,presm);
//     rec(vc,ind-1,presm+vc[ind]);
    
//     return ;
// }
ll rec(vector<ll>&vc,int ind, ll p1,ll p2)
{
    if(ind==-1)
    {
        return abs(p1-p2);
    }
    ll pick1=rec(vc,ind-1,p1+vc[ind],p2);
    ll pick2=rec(vc,ind-1,p1,p2+vc[ind]);
    return min(pick1,pick2);
}

void solve() {
  ll n;
  cin>>n;
  vi vc(n);
  FOR(i,0,n)cin>>vc[i];
  tot=accumulate(all(vc),0);
    cout<<rec(vc,n-1,0,0);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    int t = 1;
    string newTestCase = "-----------------\n";
    if (many_test)
        cin >> t;
    while (t--) {
        solve();
        debug(newTestCase);
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
    return 0;
}