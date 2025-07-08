#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 5;
ll n, m;
ll a[1005][1005];
ll f[1005][1005];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1) f[i][j] = a[i][j];
            else if(j == 1) f[i][j] = f[i - 1][j] + a[i][j];
            else f[i][j] = max({f[i - 1][j], f[i][j - 1]}) + a[i][j];
        }
    }
    cout << f[n][m];
}