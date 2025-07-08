#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int a[MAX], b[1005][1005];
int f[1005][1005];
void input()
{
    int n;
    cin >> n;
    FOR(i, 1, n * n) cin >> a[i];
    sort(a + 1, a + n * n + 1);
    int d = 1;
    int d1 = 1, d2 = 1;
    int dn1 = n, dn2 = n;
    while(d1 <= n && d2 <= n)
    {
        FOR(i, d2, dn2) f[d1][i] = a[d++];
        d1++;
        FOR(i, d1, dn1) f[i][dn2] = a[d++];
        dn2--;
        FORD(i, dn2, d2) f[dn1][i] = a[d++];
        dn1--;
        FORD(i, dn1, d1) f[i][d2] = a[d++];
        d2++;
    }
    FOR(i, 1, n) 
    {
        FOR(j, 1, n) cout << f[i][j] << " ";
        cout << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
