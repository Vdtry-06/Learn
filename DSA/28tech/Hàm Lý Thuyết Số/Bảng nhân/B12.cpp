#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;

struct xli
{
    ll d, c;
};
typedef struct xli xli;

int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n, x;
    cin >> n >> x;
    if(n * n < x) 
    {
        cout << 0;
        return 0;
    }
    xli f[100];
    int t = 0;
    for(int i = 1; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            f[t].d = i;
            f[t].c = x / i;
            t++;
        }
    }
    ll d = 0, d1 = 0;
    for(int i = 0; i < t; i++)
    {
        if(f[i].d <= n && f[i].c <= n)
        {
            if(f[i].d != f[i].c) d++;
            else d1++;
        }
        // cout << f[i].d << " " << f[i].c << endl;
    }
    // cout << d << endl << d1 << endl;
    cout << d * 2 + d1;
}