#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct data
{
    int x, y, z;
};
void solve()
{
    struct data a[4], ab, ac, ad, t;
    For(i, 0, 4) cin >> a[i].x >> a[i].y >> a[i].z;
    ab.x = a[1].x - a[0].x, ab.y = a[1].y - a[0].y, ab.z = a[1].z - a[0].z;
    ac.x = a[2].x - a[0].x, ac.y = a[2].y - a[0].y, ac.z = a[2].z - a[0].z;
    ad.x = a[3].x - a[0].x, ad.y = a[3].y - a[0].y, ad.z = a[3].z - a[0].z;
    t.x = ab.y * ac.z - ab.z * ac.y;
    t.y = ab.z * ac.x - ab.x * ac.z;
    t.z = ab.x * ac.y - ab.y * ac.x;
    if(t.x * ad.x + t.y * ad.y + t.z * ad.z == 0) cout << "YES" << endl;
    else cout << "NO" << endl; 
}
signed main()
{
    // file()
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    } 
}
