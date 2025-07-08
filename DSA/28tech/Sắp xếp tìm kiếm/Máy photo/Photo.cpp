#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6 + 5;
ll n, x, y;

void eat()
{
    cin >> n >> x >> y;
}

bool check(ll m)
{
    return m / x + m / y >= n - 1;
}

void sleep()
{
    ll l = 0, r = n * max({x, y}), ans = -1;
    while(l <= r)
    {
        ll m = (l + r) / 2;
        if(check(m))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans + min({x, y});
}

signed main()
{
    eat();
    sleep();
}