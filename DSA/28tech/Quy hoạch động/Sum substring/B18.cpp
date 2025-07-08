#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll f[MAX];
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    f[0] = s[0] - '0';
    ll ans = f[0];
    for(int i = 1; i < n; i++)
    {
        f[i] = (s[i] - '0') * (i + 1) + 1ll * 10 * f[i - 1];
        ans += 0ll + f[i];
    }
    cout << ans;
}