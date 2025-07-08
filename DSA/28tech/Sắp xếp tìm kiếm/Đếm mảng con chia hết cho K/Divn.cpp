#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e6 + 5;
map<ll, ll> mp;
ll a[MAX];
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll s = 0, d = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i];
        s = (s % n + n) % n;
        if(s == 0) d++;
        if(mp.find(s) != mp.end()) d += mp[s];
        mp[s]++;
    }
    cout << d;
}