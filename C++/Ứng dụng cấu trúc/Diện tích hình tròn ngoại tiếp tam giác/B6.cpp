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
#define PI 3.141592653589793238
#define all(x) x.begin(), x.end()
#define pr pair<string, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct area
{
    double x, y;
};
bool check(double a, double b, double c)
{
    if(a + b > c && a + c > b && c + b > a) return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    area a, b, c;
    For(i, 0, n)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        double AB = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        double BC = sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));
        double CA = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
        if(check(AB, BC, CA))
        {
            double s = 0.25 * sqrt((AB + BC + CA) * (AB + BC - CA) * (AB + CA - BC) * (BC + CA - AB));
            double r = AB * BC * CA / (4 * s);
            cout << fixed << setprecision(3) << PI * r * r;
        }
        else cout << "INVALID";
        cout << endl;
    }
}
signed main()
{
    // file();
    faster();
    solve();
}