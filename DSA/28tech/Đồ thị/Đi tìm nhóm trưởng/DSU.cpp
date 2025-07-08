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
int parent[1005];
int bac[1005];
int sz[1005];
int n, m;
void ktao()
{
    FOR(i, 1, n)
    {
        parent[i] = i;
    }
}
int find(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u != v)
    {
        if(bac[u] > bac[v] || bac[u] == bac[v] && u < v)
        {
            parent[v] = u;
        }
        else parent[u]= v;
    }
}
void input()
{
    cin >> n >> m;
    ktao();
    vector<pr> v;
    FOR(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        bac[x]++;
        bac[y]++;
        v.push_back({x, y});
    }
    for(pr p : v)
    {
        Union(p.fi, p.se);
    }
    FOR(i, 1, n)
    {
        if(i == parent[i])
        {
            cout << i << " ";
        }
    }
}
signed main()
{
    // file();
    faster();
    input();
}
