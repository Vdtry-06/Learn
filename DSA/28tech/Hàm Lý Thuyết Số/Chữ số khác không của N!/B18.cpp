#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
int a[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
ll cstc(ll n)
{
    if(n < 10) return a[n];
    if(((n / 10) % 10) % 2 == 0) return (6 * cstc(n / 5) * a[n % 10]) % 10;
    return (4 * cstc(n / 5) * a[n % 10]) % 10;
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n;
    cin >> n;
    cout << cstc(n);
}
