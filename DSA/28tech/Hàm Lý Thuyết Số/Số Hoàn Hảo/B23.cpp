#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e7+5;
using namespace std;

bool prime(ll n)
{
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

bool check(ll n)
{
    for(int i = 2; i <= 32; i++)
    {
        if(prime(i))
        {
            ll tmp = (ll)pow(2, i) - 1;
            if(prime(tmp))
            {
                ll t = (ll)pow(2, i - 1) * tmp;
                if(t == n) return 1;
            }
        }
    }
    return 0;
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll n;
    cin >> n;
    if(check(n)) cout << "YES";
    else cout << "NO";
}