#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
ll binpow(ll a, ll b, ll m)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2, m);
    if(b % 2 == 0) return (t % m) * (t % m) % m;
    return (t % m) * (t % m) % m * (a % m) % m; 
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll s = 1;
    for(int i = n - k + 1; i <= n; i++)
    {
        s = (s * i) % MOD;
    }
    for(int i = 1; i <= k; i++)
    {
        s = (s * binpow(i, MOD - 2, MOD)) % MOD;
    }
    cout << s;
}