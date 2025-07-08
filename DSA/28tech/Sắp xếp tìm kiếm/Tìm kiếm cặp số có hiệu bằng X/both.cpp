#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e6+5;
int a[MAX];
int n, x;
int main()
{
    cin >> n >> x;
    for(int &x : a) cin >> x;
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto it = lower_bound(a + i + 1, a + n, x + a[i]);
        auto it2 = upper_bound(a + i + 1, a + n, x + a[i]);
        ans += it2 - it;
    }
    if(ans) cout << 1;
    else cout << -1;
}
