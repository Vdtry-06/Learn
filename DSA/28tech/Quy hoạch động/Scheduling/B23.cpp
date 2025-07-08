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
#define end '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll f[MAX];
int n;
struct job
{
    int st, ed, profit;
}; 
job a[MAX];
void input()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i].st >> a[i].ed >> a[i].profit;
}
bool cmp(job a, job b)
{
    return a.ed < b.ed;
}
int last_pos(job a[], int l, int r, int x)
{
    int res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m].ed < x) 
        {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}
void dp()
{
    sort(a + 1, a + n + 1, cmp);
    f[1] = a[1].profit;
    FOR(i, 2, n)
    {
        int t = last_pos(a, 1, i - 1, a[i].st);
        if(t != -1) f[i] = max(f[i - 1], a[i].profit + f[t]);
        else f[i] = max(f[i - 1], (ll)a[i].profit);
    }
    cout << f[n];
}
signed main()
{
    // file();
    faster();
    input();
    dp();
}
