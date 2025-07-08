#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
bool nto(ll n)
{
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}
void snto(ll n, ll num, set<ll> &v)
{
    
    if(num > n) return;
    if(nto(num))
    {
        v.insert(num);
        for(int i = 1; i <= 9; i++)
        {
            snto(n, num * 10 + i, v);
        }
    }
    
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ll t;
    cin >> t; 
    while(t--)
    {
        ll n;
        cin >> n;
        set<ll> v;
        for(int i = 2; i <= 9; i++)
        {
            snto(n, i, v);
        }
        for(auto x : v) cout << x << " "; 
        cout << endl;
    }
}