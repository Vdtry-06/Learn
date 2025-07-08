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
bool visited[MAX], ap[MAX];// danh dau cac dinh
int disc[1005], low[1005];
vector<int> ke[MAX];
int n, m, timer = 0;
stack<int> st;
int scc = 0;
void input()
{
    cin >> n >> m;
    FOR(i, 0, m - 1)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(visited, false, sizeof(ap));
}
void DFS(int u, int par)
{
    visited[u] = true;
    disc[u] = low[u] = timer++;
    int child = 0;// so luong con
    for(int v : ke[u])
    {
        if(v == par) continue;
        if(!visited[v])
        {
            DFS(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if(par != -1 && disc[u] <= low[v])
            {
                ap[u] = true;
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if(par == -1 && child > 1) ap[u] = true;
}
signed main()
{
    // file();
    faster();
    input();
    FOR(i, 1, n)
    {
        if(!visited[i]) DFS(i, -1);
    }
    int d = 0;
    FOR(i, 1, n)
    {
        if(ap[i]) d++;
    }
    cout << d;
}
