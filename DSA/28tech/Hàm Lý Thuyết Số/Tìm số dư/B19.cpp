#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;

int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n, x;
    cin >> n >> x;
    if(x >= 32) cout << n;
    else cout << n % (1ll << x);
}