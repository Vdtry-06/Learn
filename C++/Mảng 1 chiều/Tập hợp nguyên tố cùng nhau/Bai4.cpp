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
ll ucln(ll a, ll b)
{
    if(b == 0) return a;
    return ucln(b, a % b);
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        ll t = 1ll * n * (n + 1) / 2;
        if((m + t) % 2 != 0 || (t - m) % 2 != 0 || t < m) cout << "No";
        else
        {
            ll a = (m + t) / 2;
            ll b = (t - m) / 2;
            // cout << a << " " << b;
            if(ucln(a, b) == 1) cout << "Yes";
            else cout << "No";
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
