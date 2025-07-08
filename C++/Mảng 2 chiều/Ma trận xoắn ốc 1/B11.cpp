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
int a[1005][1005];
int f[1005][1005];
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        FOR(i, 1, n) 
        {
            FOR(j, 1, m) cin >> a[i][j];
        }
        int d1 = 1, d2 = 1;
        while(d1 <= n && d2 <= m)
        {
            FOR(i, d2, m) cout << a[d1][i] << " ";
            d1++;
            FOR(i, d1, n) cout << a[i][m] << " ";
            m--;
            if(d1 <= n)
            {
                FORD(i, m, d2) cout << a[n][i] << " ";
                n--;
            }
            if(d2 <= m)
            {
                FORD(i, n, d1) cout << a[i][d2] << " ";
                d2++;
            }
        }
        cout << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
