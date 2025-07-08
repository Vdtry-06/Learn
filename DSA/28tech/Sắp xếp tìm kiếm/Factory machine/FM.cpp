#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll a[MAX], n, k;

void input()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
}

bool check(ll a[], ll n, ll pro, ll time)
{
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += time / a[i];
        if(ans >= pro) return true;
    }
    return ans >= k;
}

void binary_search_answer(ll a[], ll n, ll k)
{
    ll l = 0, r = 9e18, ans = -1;
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

signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    binary_search_answer(a, n, k);
}