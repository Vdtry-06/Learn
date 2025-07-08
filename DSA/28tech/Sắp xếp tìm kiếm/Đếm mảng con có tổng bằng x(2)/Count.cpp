#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e6 + 5;
map<ll, ll> mp;
ll a[MAX];
ll n, k;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll s = 0, d = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i];
        if(s == k) d++;
        if(mp.find(s - k) != mp.end()) d += mp[s - k];
        mp[s]++;
    }
    cout << d;
}