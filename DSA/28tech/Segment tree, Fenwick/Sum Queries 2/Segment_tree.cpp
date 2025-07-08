#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
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
ll a[MAX], t[4 * MAX];
int n, q;
void build(int v, int l, int r)
{
    if(l == r) t[v] = a[l];
    else 
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}
ll sum(int v, int tl, int tr, int l, int r)
{
    if(l > r) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(int v, int l ,int r, int pos, int val)
{
    if(l == r) t[v] = val;
    else 
    {
        int m = (l + r) / 2;
        if(pos <= m) update(2 * v, l, m, pos, val);
        else update(2 *v + 1, m + 1, r, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}
void input()
{
    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int u, v;
            cin >> u >> v;
            update(1, 0, n - 1, u - 1, v);
        }
        else 
        {
            int l, r;
            cin >> l >> r;
            cout << sum(1, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
}
signed main()
{
    // file();
    faster();
    input();
}
