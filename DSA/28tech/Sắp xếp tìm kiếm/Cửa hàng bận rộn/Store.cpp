#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
vector<pair<ll, ll>> v;
int n;
int main()
{   
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    sort(v.begin(),v.end());
    ll dem = 0, ans = 0;
    for(auto it : v)
    {
        dem += it.second;
        ans = max(ans, dem);
    }
    cout << ans << endl;
}
