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
ll a, b, n;

void eat()
{
    cin >> a >> b >> n;
}

bool sleep(ll next)
{
    return (next / a) * (next / b) >= n;
}

void code()
{
    ll l = 0, r = n * max({a, b}), ans = -1;
    while(l <= r)
    {
        ll m = (l + r) / 2;
        if(sleep(m))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans;
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
