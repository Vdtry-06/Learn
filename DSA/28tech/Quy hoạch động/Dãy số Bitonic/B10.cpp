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
int f[MAX], p[MAX];
int a[MAX];
int n, mx = 0;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
void dp()
{
    fr(i, 1, n)
    {
        f[i] = a[i];
        fr(j, 1, i)
        {
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + a[i]);
        }
    }
    fr1(i, n, 1)
    {
        p[i] = a[i];
        fr1(j, n, i)
        {
            if(a[i] > a[j]) p[i] = max(p[i], p[j] + a[i]);
        }
    }
    fr(i, 1, n)
    {
        mx = max(mx, f[i] + p[i] - a[i]);
    }
    cout << mx;
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
