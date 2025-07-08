#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define pr pair<int, ll>
#define vi vector<int> 
#define vll vector<ll>
#define fi first
#define se second
#define sz size()
#define end '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll f[MAX];
int n;
void input()
{
    cin >> n;
}
ll binpow(int a, int b)
{
    if(b == 0) return 1;
    ll t = binpow(a, b / 2) % MOD;
    if(b % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD;
}

void dp()
{
    int s = n * (n + 1) / 2;
    if(s % 2 == 0)
    {
        s /= 2;
        f[0] = 1;
        FOR(i, 1, n)
        {
            FORD(j, s, i)
            {
                f[j] = f[j] + f[j - i];
                f[j] %= MOD;
            }
        }
        // cout << f[s] / 2;
        int bp = binpow(2, MOD - 2);
        cout << (ll)f[s] * bp % MOD;
    }
    else cout << 0;
}
signed main()
{
    // file();
    faster();
    input();
    dp();
}
