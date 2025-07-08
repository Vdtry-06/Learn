#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll n, k;
struct matrix
{
    ll f[32][32];
};
matrix nhan(matrix a, matrix b)
{
    matrix s;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            s.f[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                s.f[i][j] += (a.f[i][k] * b.f[k][j]) % MOD;
                s.f[i][j] %= MOD;
            }
        }
    }
    return s;
}
matrix binpow(matrix a, ll m)
{
    if(m == 1) return a;
    matrix x = binpow(a, m / 2);
    if(m % 2 == 0) return nhan(x, x);
    return nhan(a, nhan(x, x));
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    matrix a;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a.f[i][j];
        }
    }
    matrix res = binpow(a, k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res.f[i][j] << " ";
        }
        cout << endl;
    }
}