#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define pr pair<int, ll>
#define vi vector<int> 
#define vll vector<ll>
#define fi first
#define se second
#define sz size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<int> a[MAX];
bool visited[MAX];
int n, m;
void input()
{
    cin >> n >> m;
    FOR(i, 0, m - 1)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
}

void DFS(int u)
{
    visited[u] = true;
    for(int v : a[u])
    {
        if(!visited[v]) DFS(v);
    }
}
void tplt()
{
    int cnt = 0;
    FOR(i, 1, n)
    {
        if(!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt;
}
signed main()
{
    file();
    faster();
    input();
    tplt();
}
