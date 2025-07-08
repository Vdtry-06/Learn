#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e7+5;

ll solove(ll n, ll p)
{
    ll ans = 0;
    for(ll i = p;i <= n; i *= p)
    {
        ans += n / i;
    }
    return ans;
}

int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n;
    int m;
    cin >> n >> m;
    cout << solove(n, m);
}