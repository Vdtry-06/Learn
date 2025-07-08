#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define pr pair<int, int>
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
int a[MAX];
int n;
vi v;
void input()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}
int first_pos(vi &v, int x)
{
    int l = 0, r = v.sz - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(v[m] >= x)
        {
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}
void dp()
{
    FOR(i, 1, n)
    {
        int t = first_pos(v, a[i]);
        if(t != -1) v[t] = a[i];
        else v.push_back(a[i]);
    }
    cout << v.sz;
}
signed main()
{
    // file();
    faster();
    input();
    dp();
}
