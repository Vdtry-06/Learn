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
int color[MAX];
int n, m;
void input()
{
    cin >> n >> m;
    FOR(i, 0, m - 1)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        //ke[y].push_back(x);
    }
}

bool DFS(int u)
{
    color[u] = 1; // dang duyet
    for(int v : ke[u])
    {
        if(color[v] == 0) // chua duyet
        {
            if(DFS(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;// duyet xong
    return false;
}
signed main()
{
    // file();
    faster();
    input();
    FOR(i, 1, n)
    {
        if(color[i] == 0)
        {
            if(DFS(i)) 
            {
                cout << 1;
                return 0;
            } 
        }
    }
    cout << 0;
}
