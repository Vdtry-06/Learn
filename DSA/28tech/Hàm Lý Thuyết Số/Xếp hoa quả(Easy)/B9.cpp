#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
ll gt(int n)
{
    if(n == 0) return 1;
    ll s = 1;
    for(int i = 1; i <= n; i++)
    {
        s = 1ll * s * i;
    }
    return s;
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k1, k2, k3, k4;
    cin >> n;
    cin >> k1 >> k2 >> k3 >> k4;
    // cout << gt(n);
    cout << gt(n) / gt(k1) / gt(k2) / gt(k3) / gt(k4);
}