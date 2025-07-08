#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
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
int d[5] = {0};
int n;
void input()
{
    cin >> n;
    For(i, 0, n) 
    {
        int x; cin >> x;
        d[x]++;
    }
    int ans = d[4];
    ans += d[3];
    d[1] -= min(d[1], d[3]);
    ans += d[2] / 2;
    if(d[2] % 2 == 1)
    {
        ans++;
        d[1] -= min(d[1], 2);
    }
    ans += d[1] / 4;
    if(d[1] % 4 != 0) ans++;
    cout << ans;
}
signed main()
{
    // file();
    faster();
    input();
    
}
