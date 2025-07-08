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
vector<int> ke[1005];
bool visited[1005];
int n, m, cnt = 0;
void input()
{
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u)
{
    cnt++;
    visited[u] = true;
    for(int v : ke[u])
    {
        if(!visited[v])
        {
            DFS(v);
        }
    }
}
signed main()
{
    // file();
    faster();
    input();
    ll s = 0;
    FOR(i, 1, n)
    {
        if(!visited[i])
        {
            cnt = 0;
            DFS(i);
            s += 1ll * cnt * (cnt - 1) / 2;
        }
    }
    if(s == m) cout << "YES";
    else cout << "NO";
}
