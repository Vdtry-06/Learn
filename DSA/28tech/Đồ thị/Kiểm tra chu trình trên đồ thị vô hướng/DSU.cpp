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
bool check = false;
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
    int x = Find(parent[u]);
    parent[u] = x;
    return x;
    // return parent[u] = Find(parent[u]);

}
// toi uu gop
bool Union(int u, int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;// da thuoc tplt
    else
    {
        if(sz[x] > sz[y])
        {
            parent[y] = x;
            sz[x] += sz[y];
        }
        else
        {
            parent[x] = y;
            sz[y] += sz[x];
        }
        return true;
    }
}
signed main()
{
    // file();
    faster();
    cin >> n >> m;
    ktao();
    FOR(i, 0, m - 1)
    {
        int x, y;
        cin >> x >> y;
        if(Union(x, y) == false) check = true;
        // da thuoc tplt
    }
    if(check) cout << 1;
    else cout << 0;
}