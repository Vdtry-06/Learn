#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i <= r; i++)
#define fr1(i, r, l) for(int i = r; i >= l; i--)
#define pr pair<int, int>
#define vt vector<int> 
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int f[105][25005];
int a[MAX];
int c, n;
void input()
{
    cin >> c >> n;
    fr(i, 1, n) cin >> a[i];
}
void dp()
{
    memset(f, 0, sizeof(f));
    fr(i, 1, n)
    {
        fr(j, 0, c)
        {
            f[i][j] = f[i - 1][j];
            if(j >= a[i]) f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + a[i]);
        }
    }
    cout << f[n][c];
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    dp();
}
