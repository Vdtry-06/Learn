#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i < r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define pr pair<int, ll>
#define vi vector<int> 
#define vll vector<ll>
#define fi first
#define se second
#define sz size()
#define end '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int f[1005][1005];
int n, m;
void input()
{
    cin >> n >> m;
}
int dp(int n, int m)
{
    if(n == m) return 0;
    if(f[n][m]) return f[n][m];
    int res = 1e9;
    FOR(i, 1, n)
    {
        res = min(res, dp(i, m) + dp(n - i, m) + 1);
    }
    FOR(j, 1, m)
    {
        res = min(res, dp(n, j) + dp(n, m - j) + 1);
    }
    return f[n][m] = res;
}
signed main()
{
    // file();
    faster();
    input();
    cout << dp(n, m);
}
