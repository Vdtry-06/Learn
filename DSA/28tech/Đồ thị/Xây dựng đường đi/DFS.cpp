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
vector<int> ke[1005], v;
bool visited[1005];
int n, m;
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
    visited[u] = true;
    for(int v : ke[u])
    {
        if(!visited[v]) 
        {
            DFS(v);
        }
    }
}
int dem()
{
    int cnt = 0;
    FOR(i, 1, n)
    {
        if(!visited[i])
        {
            v.push_back(i);
            DFS(i);
            cnt++;
        }
    }
    return cnt;
}
signed main()
{
    // file();
    faster();
    input();
    int cnt = dem() - 1;
    cout << cnt << endl;
    FOR(i, 1, v.size() - 1)
    {
        cout << v[i - 1] << " " << v[i] << endl;
    }
}
