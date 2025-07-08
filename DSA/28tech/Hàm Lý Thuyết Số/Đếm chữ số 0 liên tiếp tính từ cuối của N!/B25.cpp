#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e7+5;
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n;
    cin >> n;
    ll d = 0, ans = 0;
    for(ll i = 5; i <= n; i *= 5)
    {
        ans += (n / i) % MOD;
        ans %= MOD;
    }
    cout << ans;
}