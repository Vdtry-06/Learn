#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int parent[MAX], sz[MAX];
int n, m, mx = 0;
void ktao()
{
    for(int i= 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u)
{
    if(u == parent[u]) return u;
    int x = Find(parent[u]);
    parent[u] = x;
    return x;
}
bool Union(int v, int u)
{
    int x = Find(v);
    int y = Find(u);
    if(x == y) return false;
    else 
    {
        
        if(sz[x] > sz[y]) 
        {
            parent[y] = x;
            sz[x] += sz[y];
            mx = max(mx, sz[x]);
        }
        else 
        {
            parent[x] = y;
            sz[y] += sz[x];
            mx = max(mx, sz[y]);
        }
        return true;
    }
}
int main()
{
    cin >> n >> m;
    ktao();
    int cnt = n;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if(Union(x, y)) cnt--;
        cout << cnt << " " << mx << endl;
    }
}