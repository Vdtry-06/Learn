#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct data
{
    double x, y;
};
void solve()
{
    int n;
    cin >> n;
    struct data a[n];
    For(i, 0, n) cin >> a[i].x >> a[i].y;
    double s = 0.0;
    For(i, 1, n) s += (a[i].x - a[i - 1].x) * (a[i].y + a[i - 1].y) / 2.0;
    s += (a[0].x - a[n - 1].x) * (a[0].y + a[n - 1].y) / 2.0;
    cout << fixed << setprecision(3) << abs(s) << endl;
}
signed main()
{
    // file()
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    } 
}
