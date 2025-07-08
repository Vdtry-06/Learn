#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
bool fibo(ll n)
{
    if(n == 0 || n == 1 || n == 2) return true;
    ll f1 = 1, f2 = 2;
    for(ll i = 3; i <= MAX; i++)
    {
        ll f = f1 + f2;
        f1 = f2;
        f2 = f;
        if(f == n) 
        {
            return true;
        }
    }
    return false;
    //for(int i = 1; i <= n; i++) cout << f[i] << " ";
    
}

int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if(fibo(n)) cout << "YES";
    else cout << "NO";
}