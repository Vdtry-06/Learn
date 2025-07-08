#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 5;
int a[MAX];
int n, k;
int main()
{
    cin >> n >> k;
    for(int &x : a) cin >> x;
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n ; i++)
    {
        auto it = upper_bound(a + i + 1, a + n, k - a[i]);
        ans += n - (it - a);
    }
    cout << ans;
}