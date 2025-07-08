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
int a[1005][1005];
bool visited[MAX];
int n, m;
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
}

void DFS(int u)
{
    visited[u] = true;
    for(int v : ke[u])
    {
        if(!visited[v]) 
        {
            DFS(v);
        }
    }
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int y : ke[x])
        {
            if(!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
int tplt()
{
    int cnt = 0;
    FOR(i, 1, n)
    {
        if(!visited[i])
        {
            cnt++;
            //DFS(i);
            BFS(i);
        }
    }
    return cnt;
}
void dinh_tru()
{
    int ans = 0;
    int cc = tplt(); // so tplt ban dau
    FOR(i, 1, n)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true; // loai bo i khoi do thi
        if(cc < tplt()) ans++;
    }
    cout << ans;
}
signed main()
{
    // file();
    faster();
    input();
    dinh_tru();
}
