#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
ll t[4 * MAX], a[MAX];
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
ll sum(int v, int l1, int r1, int l, int r)
{
    if(l > r) return 0;
    if(l == l1 && r == r1) return t[v];
    int m1 = (l1 + r1) / 2;
    return sum(v * 2, l1, m1, l, min(r, m1)) + sum(2 * v + 1, m1 + 1, r1, max(l, m1 + 1), r);
}
void input()
{
    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum(1, 0, n - 1, l - 1, r - 1) << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
