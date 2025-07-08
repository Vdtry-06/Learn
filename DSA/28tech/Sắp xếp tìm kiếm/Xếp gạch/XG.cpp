#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    for(ll &x : a) cin >> x;
    sort(a, a + n , greater<ll>());
    ll dc = 1e9, d = 0;
    for(int i = 0; i < n; i++)
    {
        if(dc == 0) break;
        d++;
        dc = min(dc - 1, a[i]);
    }
    cout << d;
}