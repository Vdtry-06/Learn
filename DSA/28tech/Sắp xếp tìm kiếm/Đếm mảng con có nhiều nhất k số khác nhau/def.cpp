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
    ll l = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        while(mp.size() > k)
        {
            mp[a[l]]--;
            if(mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        ans += i - l + 1;
    }
    cout << ans;
}