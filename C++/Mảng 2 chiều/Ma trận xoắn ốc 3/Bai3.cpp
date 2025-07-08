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
vector<int> v;
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        FOR(i, 1, n)
        {
            FOR(j, 1, m) cin >> a[i][j];
        }
        int h1 = 1, c1 = 1;
        int hn = n, cm = m;
        int d = 1;
        while(h1 <= n && c1 <= m && h1 <= hn && c1 <= cm)
        {
            FOR(i, c1, cm) v.push_back(a[h1][i]);
            h1++;
            FOR(i, h1, hn) v.push_back(a[i][cm]);
            cm--;
            if(h1 <= hn)
            {
                FORD(i, cm, c1) v.push_back(a[hn][i]);
                hn--;
            }
            if(c1 <= cm)
            {
                FORD(i, hn, h1) v.push_back(a[i][c1]);
                c1++;
            }
        }
        cout << v[k - 1] << endl;
        v.clear();
    }
}
signed main()
{
    // file();
    faster();
    input();
}
