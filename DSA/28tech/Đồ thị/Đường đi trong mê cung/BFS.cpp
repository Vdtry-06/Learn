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
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[1005];
int a[1005][1005];
int parent[1005];
int x, y, x2, y2;
int n;
void input()
{
    cin >> n;
    cin >> x >> y >> x2 >> y2;
    FOR(i, 1, n)
    {
        FOR(j, 1, n) cin >> a[i][j];
    }
}
int d[1005][1005];
int BFS()
{
    queue<pr> q;
    q.push({x, y});
    a[x][y] = 0;
    d[x][y] = 0;
    while(!q.empty())
    {
        pr it = q.front(); q.pop();
        int i = it.fi, j = it.se;
        if(i == x2 && j == y2) return d[x2][y2];
        else
        {
            FOR(k, 0, 7)
            {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1)
                {
                    q.push({i1, j1});
                    a[i1][j1] = 0;
                    d[i1][j1] = d[i][j] + 1;
                }
            }
        }
    }
    return -1;
}
signed main()
{
    // file();
    faster();
    input();
    cout << BFS();
}
