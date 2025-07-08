#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
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
ll binpow(int a, int b)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2);
    if(b % 2 == 0) return t * t;
    return t * t * a;
}
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y, z, n;
        cin >> x >> y >> z >> n;
        ll s = lcm(x, y);
        ll ans = lcm(s, z);
        ll k = binpow(10, n - 1);
        if(k % ans == 0) cout << k;
        else 
        {
            ll tmp = k / ans;
            if((tmp + 1) * ans < binpow(10, n)) cout << (tmp + 1) * ans;
            else cout << -1; 
        }
        cout << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}