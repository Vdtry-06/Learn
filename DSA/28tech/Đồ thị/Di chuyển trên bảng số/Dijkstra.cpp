#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
typedef pair<int, pair<int, int>> prr;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fi first
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<pr> ke[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[505][505];
int d[505][505];
int n, m;
void input()
{
    cin >> n >> m;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}
void dijktra(int i, int j)
{
    priority_queue<prr, vector<prr>, greater<prr>> Q;
    Q.push({0, {i, j}});
    d[i][j] = a[i][j];
    while(!Q.empty())
    {
        prr top = Q.top(); Q.pop();
        int kc = top.fi;
        pr p = top.se;
        if(kc > d[p.fi][p.se]) continue;
        FOR(k, 0, 3)
        {
            int i1 = p.fi + dx[k];
            int j1 = p.se + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m)
            {
                if(d[i1][j1] > d[p.fi][p.se] + a[i1][j1])
                {
                    d[i1][j1] = d[p.fi][p.se] + a[i1][j1];
                    Q.push({d[i1][j1], {i1, j1}});
                }
            }
        }
    }
    cout << d[n][m];
}
signed main()
{
    // file();
    faster();
    input();
    dijktra(1, 1);
}