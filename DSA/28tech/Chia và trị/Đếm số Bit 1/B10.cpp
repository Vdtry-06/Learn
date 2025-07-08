#include<bits/stdc++.h>
#define fr(i, l, r) for(long long i = l; i <= r; i++)
#define fr1(i, r, l) for(int i = r; i >= l; i--)
#define pr pair<int, int>
#define vt vector<int> 
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll n, l, r, res = 0;
vector<ll> a;
void input()
{
    cin >> n >> l >> r;
}
void xuly(ll n) // tim dc tat ca vtri trung tam
{
    int t = 0;
    ll mu = 1;
    while(n / 2 > 0)
    {
        t++;
        if(t == 1) 
        {
            a.push_back(2);
            mu = 2;
        }
        else  
        {
            mu *= 2;
            a.push_back(mu);
        }
        n /= 2;
    }
}
ll dca(ll k, ll n, ll pos)
{
    if(k % 2 == 1) return 1;
    if(k < a[pos]) return dca(k, n / 2, pos - 1);
    else if(k == a[pos]) return n % 2;
    else return dca(2 * a[pos] - k, n / 2, pos - 1);
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    xuly(n);
    fr(i, l, r) res += dca(i, n, a.size() - 1);
    cout << res;
}
