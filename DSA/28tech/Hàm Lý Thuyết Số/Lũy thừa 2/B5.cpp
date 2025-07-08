#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1E9+7;
const int MAX = 1e6+5;

ll binpow(ll a, ll b, ll mod)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2, mod);
    if(b % 2 == 0) return (t % mod) * (t % mod) % mod;
    return (t % mod) * (t % mod) % mod * a  % mod;
}
int main() 
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b,c,MOD-1), MOD) << endl;
    }
}
