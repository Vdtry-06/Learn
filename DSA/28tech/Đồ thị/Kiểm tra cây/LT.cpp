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
vector<int> ke[MAX];
bool visited[MAX];
int parent[1005];
int n, m, cnt = 0;
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
    DFS(1);
    if(cnt == n && m == n - 1) cout << 1;
    else cout << 0;
}
