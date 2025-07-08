#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
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
struct timed
{
    int h, m, s;
};

void nhap(timed &ds)
{
    cin >> ds.h >> ds.m >> ds.s;
}
bool cmp(timed a, timed b)
{
    if(a.h == b.h)
    {
        if(a.m == b.m) 
        {
            return a.s < b.s;
        }
        return a.m < b.m;
    }
    return a.h < b.h;
}
void sapxep(timed ds[], int n)
{
    sort(ds, ds + n, cmp);
}
void in(timed ds[], int n)
{
    For(i, 0, n)
    {
        cout << ds[i].h << " " << ds[i].m << " " << ds[i].s << endl;
    }
}
void solve()
{
    timed ds[5000];
    int n;
    cin >> n;
    For(i, 0, n) nhap(ds[i]);
    sapxep(ds, n);
    in(ds, n);
}
int main()
{
    // file();
    faster();
    solve();
}