#include<bits/stdc++.h>
#define for(i, l, r) for(int i = l; i < r; i++)
#define for1(i, r, l) for(int i = r - 1; i >= l; i--)
#define pr pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll a[MAX], n, k;

void eat()
{
    cin >> n >> k;
    for(i, 0, n) cin >> a[i];
}

bool sleep(double cut)
{
    ll ans = 0;
    for(i, 0, n)
    {
        ans += (ll)(a[i] / cut);
    }
    return ans >= k;
}

void code()
{
    double l = 0, r = 9e18, ans = -1;
    for(i, 1, 101)
    {
        double m = (l + r) / 2;
        if(sleep(m))
        {
            ans = m;
            l = m;
        }
        else r = m;
    }
    cout << fixed << setprecision(6) << ans << endl;
}

signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eat();
    code();
}
