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
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int ke[1005], parent[1005];
int sz[1005];
int n, m;
void ktao()
{
    FOR(i, 1, n) 
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
// toi uu nen duong
int Find(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
    // int x = Find(parent[u]);
    // parent[u] = x;
    // return x;
}
// toi uu gop
bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if(u == v) return false;// da thuoc tplt
    else
    {
        if(sz[u] > sz[v])
        {
            parent[v] = u;
            sz[u] += sz[v];
        }
        else
        {
            parent[u] = v;
            sz[v] += sz[u];
        }
        return true;
    }
}
void input()
{
    cin >> n >> m;
    ktao();
    FOR(i, 0, m - 1)
    {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(Find(x) == Find(y)) cout << 1;
        else cout << -1;
        cout << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}