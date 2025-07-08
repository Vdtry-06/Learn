#include<bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
ll n, k, a[MAX];
void input()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
}
bool check(ll a[], ll n, ll k, ll sum)
{
    ll s = 0, d = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i];
        if(s > sum)
        {
            d++;
            s = a[i];
        }
    }
    d++;
    return d <= k;
}
void binary_search_answer(ll a[], ll n, ll k)
{
    ll l = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        r += a[i];
        l = max(l, a[i]);
    }
    ll ans = -1;
    while(l <= r)
    {
        ll m = (l + r) / 2;
        if(check(a, n, k, m))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans;
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    binary_search_answer(a, n, k);
}
