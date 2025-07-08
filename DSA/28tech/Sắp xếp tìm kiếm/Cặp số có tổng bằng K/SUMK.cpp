#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[n];
    for(ll &x : a) cin >> x;
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto it = lower_bound(a + i + 1, a + n, k - a[i]);// ptu dau tien  >= k - a[i]
        auto it1 = upper_bound(a + i + 1, a + n, k - a[i]); // ptu dau tien > k - a[i]
        ans += it1 - it;
    }
    cout << ans;
}
