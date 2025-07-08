#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll binpow(ll a, ll b)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2) % MOD;
    if(b % 2 == 0) return (t * t) % MOD;
    return ((t * t) % MOD * a) % MOD;
}

ll ucln(ll a, ll b)
{
    if(b == 0) return a;
    return ucln(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    For(i, 0, n) cin >> a[i];
    ll uc1 = a[0];
    For(i, 1, n)
    {
        uc1 = ucln(uc1, a[i]);
    }
    ll t = 1;
    For(i, 0, n)
    {
        t = (t * a[i]) % MOD;
    }
    cout << binpow(t, uc1) << endl;
}

int main()
{
    faster();
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}