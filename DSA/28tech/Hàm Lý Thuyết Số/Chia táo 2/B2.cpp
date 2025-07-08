#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
ll th(int n, int k) 
{
    ll res = 1;
    for (int i = 1; i <= k; i++) 
    {
        res = res * (n - k + i) / i;
    }
    return res;
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    cout << th(n + m - 1, n - 1);
}