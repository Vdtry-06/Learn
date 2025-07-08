#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
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
int n, m, a[1005][1005];
int check[1005][1005];
int d[1005][1005];
void input()
{
    cin >> n >> m;
    FOR(i, 1, n)
    {
        FOR(j, 1, m) cin >> a[i][j];
    }
    memset(check, false, sizeof(check));
    memset(d, 0, sizeof(d));
}
void bfs(int i, int j)
{
    queue<pr> q;
    q.push({i, j});
    check[i][j] = 1;
    while(!q.empty())
    {
        pr tmp = q.front(); q.pop();
        int i = tmp.fi, j = tmp.se;
        if(i == n && j == m) break;
        if(i + a[i][j] <= n && !check[i + a[i][j]][j])
        {
            q.push({i + a[i][j], j});
            d[i + a[i][j]][j] = d[i][j] + 1;
            check[i + a[i][j]][j] = 1;
        }
        if(j + a[i][j] <= m && !check[i][j + a[i][j]])
        {
            q.push({i, j + a[i][j]});
            d[i][j + a[i][j]] = d[i][j] + 1;
            check[i][j + a[i][j]] = 1;
        }
    } 
}
signed main()
{
    // file();
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        input();
        bfs(1, 1);
        if(!check[n][m]) cout << -1;
        else cout << d[n][m];
        cout << endl;
    }
}