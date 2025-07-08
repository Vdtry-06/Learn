#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1E9+7;
const int MAX = 1e6+5;

int main() 
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll d[n+1][n+1];
    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(j == 0 || j == i) d[i][j] = 1;
            else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % MOD;
            d[i][j] %= MOD;
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
