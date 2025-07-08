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
ll bin_pow(ll a, ll b, ll m)
{
    if(b == 0) return 1;
    ll t = bin_pow(a, b / 2, m);
    if(b % 2 == 0) return t % m * t % m;
    return t % m * t % m * a % m;
}
ll mod(string a, ll b)
{
    ll ans = 0;
    For(i, 0, a.size())
    {
        ans = (ans * 10 + a[i] - '0') % b;
    }
    return ans;
}
void solve()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string a;
        ll b, c;
        cin >> a >> b >> c;
        cout << bin_pow(mod(a, c), b, c) << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}
