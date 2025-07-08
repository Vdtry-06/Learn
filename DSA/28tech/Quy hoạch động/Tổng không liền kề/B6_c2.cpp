#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 7;
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll f[n + 5] = {0};
    f[1] = a[1];
    f[2] = max(a[2], a[1]);
    for(int i = 3; i <= n; i++)
    {
        f[i] = max(f[i - 2] + a[i], f[i - 1]);
    }
    cout << f[n];
}