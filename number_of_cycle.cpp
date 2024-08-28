// Author: MD.Shahadat Hossain Bhuian
// Codeforces userName : __Shahadat__
// CodeChef userName : shahadat_43
//---------------------------------------------

// Libary 
#include<bits/stdc++.h>
using namespace std;

// Type definition
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vstr;
typedef vector<pll> vpl;
typedef set<ll> sll;

// Loop 
#define rep(i, n) for (ll i = 0; i < n;i++)
#define rev(i, n) for (ll i = n - 1; i >= 0;i--)

// Printing statement
#define dp_x(x) cout<<x<<endl
#define dp_xy(x,y) cout<<x<<" "<<y<<endl
#define nl cout<<"\n"
#define printArray(v) for(auto k:v)cout<<k<<" "
#define yes dp_x("Yes")
#define no dp_x("No")

// STL operation 
#define pb push_back
#define in insert
#define all(v) v.begin(),v.end()
#define asc(v) sort(all(v))
#define dsc(v) asc(v),reverse(all(v))
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL);

// Precalculation
const ll mod = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

ll lenN(ll n)
{
    ll res = 0;
    while (n != 0)
    {
        res++;
        n /= 10;
    }
    return res;
}

ll binExp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// Solution Start Here
const ll N = 1e5 + 10;
bool visited[N];
vll g[N];
bool cycle(ll vertex, ll parent) {
    visited[vertex] = true;
    bool isLoopExist = false;
    for (ll child : g[vertex]) {
        if (visited[child] and child == parent)continue;
        if (visited[child])return true;
        isLoopExist |= cycle(child, vertex);
    }
}
void solve() {
    ll n, m;
    cin >> n >> m;
    rep(i, m) {
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    bool isLoopExist = false;
    for (ll i = 1;i <= n;i++) {
        if (visited[i])continue;
        if (cycle(i, 0)) {
            isLoopExist = true;
            break;
        }
    }
    dp_x(isLoopExist);
}

int main() {
    Faster;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
