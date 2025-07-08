#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct matrix 
{
    ll f[2][2];
};
matrix nhan(matrix a, matrix b)
{
    matrix s;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            s.f[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                s.f[i][j] += (a.f[i][k] * b.f[k][j]) % MOD;
                s.f[i][j] %= MOD;
            }
        }
    }
    return s;
}
matrix binpow(matrix a, ll n)
{
    if(n == 1) return a;
    matrix x = binpow(a, n / 2);
    if(n % 2 == 0) return nhan(x, x);
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
    a.f[0][0] = a.f[1][0] = a.f[0][1] = 1;
    a.f[1][1] = 0;
    ll n;
    cin >> n;
    matrix res = binpow(a, n);
    cout << res.f[1][0];
}