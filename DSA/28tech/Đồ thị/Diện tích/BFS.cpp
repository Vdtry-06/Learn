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
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char a[1005][1005];
int n, m;
void input()
{
    cin >> n >> m;
    FOR(i, 1, n)
    {
        FOR(j, 1, m) cin >> a[i][j];
    }
}

int BFS(int i, int j)
{
    queue<pr> q;
    q.push({i, j});
    a[i][j] = '#';
    int cnt = 0;
    while(!q.empty())
    {
        pr it = q.front(); q.pop();
        int i = it.fi, j = it.se;
        cnt++;
        FOR(k, 0, 3)
        {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.')
            {
                q.push({i1, j1});
                a[i1][j1] = '#';
            }
        }
    }
    return cnt;
}
signed main()
{
    // file();
    faster();
    input();
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(a[i][j] == '.')
            {
                cout << BFS(i, j) << " ";
            }
        }
    }
}
