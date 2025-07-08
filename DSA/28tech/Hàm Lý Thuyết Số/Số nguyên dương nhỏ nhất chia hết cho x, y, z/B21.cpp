#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e7+5;
using namespace std;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b; 
}
ll binpow(ll a,int b)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2);
    if(b % 2 == 0) return t * t;
    return t * t * a;
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll x, y, z;
    int n;
    cin >> x >> y >> z >> n;
    ll t = lcm(x, lcm(y , z));
    if(t > binpow(10, n - 1)) cout << -1;
    else cout << (binpow(10, n - 1) / t + 1) * t;
}   