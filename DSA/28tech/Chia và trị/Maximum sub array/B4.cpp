#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i <= r; i++)
#define fr1(i, r, l) for(int i = r; i >= l; i--)
#define pr pair<int, int>
#define vt vector<int> 
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int a[MAX], n;
ll s = 0;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
ll xuly(int a[], int l, int m, int r)
{
    ll sl = 0, sr = 0, ml = 0, mr = 0;
    fr1(i, m, l)
    {
        sl += a[i];
        ml = max(ml, sl);
    }
    fr(i, m + 1, r)
    {
        sr += a[i];
        mr = max(mr, sr);
    }
    return ml + mr;
}
ll dac(int a[], int l, int r)
{
    if(l == r) return a[l];
    int m = (l + r) / 2;
    return max({dac(a, l, m), dac(a, m + 1, r), xuly(a, l , m, r)});
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << dac(a, 1, n);
}