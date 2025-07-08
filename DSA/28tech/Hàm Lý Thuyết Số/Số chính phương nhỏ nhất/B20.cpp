#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
struct xli
{
    ll gt,ts;
};
typedef struct xli xli;
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n;
    cin >> n;
    ll m = n;
    map<ll, ll> f;
    xli a[17];
    //map<ll,pair<ll, ll>> p;
    ll d = 0, t = 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        d = 0;
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                d++;
                n /= i;
            }
            a[t].gt = i;
            a[t].ts = d;
            t++;
        }
    }
    if(n > 1)
    {
        a[t].gt = n;
        a[t].ts = 1;
        t++;
    }
    ll s = 1;
    for(int i = 0; i < t; i++)
    {
        if(a[i].ts % 2 != 0)
        {
            a[i].ts++;
            s *= a[i].gt;
        }
        //cout << a[i].gt << " " << a[i].ts << endl;
    }
    cout << 1ll * s * m;
}