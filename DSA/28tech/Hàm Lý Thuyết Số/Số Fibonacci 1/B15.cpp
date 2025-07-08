#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
void fibo(ll n)
{
    ll f[n];
    f[1] = 0, f[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
        f[i] %= MOD;
        //cout << f[i] << " ";
    }
    //for(int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << f[n % MOD];
}

int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    fibo(n);
}