#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for(ll &x : a) cin >> x;
    sort(a, a + n, greater<ll>());
    ll s = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] - i > 0)
        {
            s += a[i] - i;
        }
        else break;
    }
    cout << s;
}