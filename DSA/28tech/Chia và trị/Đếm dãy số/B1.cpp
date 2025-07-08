#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll binpow(ll a, ll b)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2);
    if(b % 2 == 0) return (t * t) % MOD;
    return (t * t) % MOD * a % MOD;
}
int main()
{
    ll n;
    cin >> n;
    cout << binpow(2, n - 1);
}