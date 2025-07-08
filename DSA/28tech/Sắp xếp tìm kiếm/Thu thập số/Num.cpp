#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
int f[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        f[x] = i;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(f[i] < f[i - 1]) ans++;
    }
    cout << ans;
}