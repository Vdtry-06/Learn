#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
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
int n, m, s;
void input()
{
    cin >> n >> m >> s;
    FOR(i, 0, m - 1)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
}
void dijktra(int s)
{
    priority_queue<pr, vector<pr>, greater<pr>> Q;
    // {khoang cach, dinh}
    Q.push({0, s});
    vll d(n + 1, 1e9);
    d[s] = 0;
    while(!Q.empty())
    {
        // lay ra dinh ngan nhat tu dinh s
        pr top = Q.top(); Q.pop();
        int kc = top.fi;
        int u = top.se;
        if(kc > d[u]) continue;
        // relaxation: cap nhat khoang cach tu s toi moi dinh ke vs u
        for(pr it : ke[u])
        {
            int v = it.fi, w = it.se;
            // kc dinh u -> v = w kh: (u, v) = w
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    FOR(i, 1, n) cout << d[i] << " ";
}
signed main()
{
    // file();
    faster();
    input();
    dijktra(s);
}