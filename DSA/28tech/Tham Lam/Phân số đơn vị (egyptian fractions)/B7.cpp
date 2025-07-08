#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
struct pso
{
    ll t, m;
    void rutgon()
    {
        ll k = gcd(t, m);
        t /= k;
        m /= k;
    }
    pso operator - (pso b)
    {
        ll m1 = m * b.m;
        ll t1 = t * b.m - m * b.t;
        pso res = pso{t1, m1};
        res.rutgon();
        return res;
    }
    void in()
    {
        cout << t << "/" << m;
    }
};
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pso a;
    cin >> a.t >> a.m;
    while(a.t != 0)
    {
        ll x = ceil(1.0 * a.m / a.t);
        pso tmp = pso{1, x};
        tmp.in();
        a = a - tmp;
        if(a.t != 0) cout << " + ";
    }
}
