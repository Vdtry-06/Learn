#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(ll i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll b, p;
        cin >> b >> p;
        ll k = b / p, d = 0, ans = 0;
        b %= p;
        FOR(i, 1, b)
        {
            if(i * i % p == 1) d++;
        }
        ans = d;
        FOR(i, b + 1, p - 1)
        {
            if(i * i % p == 1) d++;
        }
        ans += d * k;
        cout << ans << endl;
    }
}
int main()
{
    // file();
    faster();
    input();
}
