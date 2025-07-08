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
bool visited[1005];
vector<int> ke[1005];
int d[1005];
int n;
void input()
{
    cin >> n;
    FOR(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        //ke[x].push_back(x);
    }
}
void DFS(int u)
{
    visited[u] = true;
    for(int v : ke[u])
    {
        if(!visited[v]) 
        {
            d[v] = d[u] + 1;
            DFS(v);
        }
    }
}
signed main()
{
    // file();
    faster();
    input();
    d[1] = 0;
    DFS(1);
    FOR(i, 1, n) cout << d[i] << " ";
}
