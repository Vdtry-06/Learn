#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;

int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n;
    cin >> n;
    // vector<map<ll, ll>> mp(n); 
    map<ll, ll> mp;
    while (n--)
    {
        ll x;
        cin >> x;
        for(int i = 2; i <= sqrt(x); i++)
        {
            if(x % i == 0)
            {
                while(x % i == 0)
                {
                    mp[i]++;
                    x /= i;
                }
            }
        }
        if(x > 1)
        {
            mp[x]++;
        }
        //for(auto x : mp) cout << x.first << " " << x.second << endl;
    }
    ll s = 1;
    for(auto x : mp)
    {
        s *= (x.second + 1) % MOD;
        s %= MOD;
        //cout << x.first << " " << x.second << endl;
    }
    cout << s;
}
