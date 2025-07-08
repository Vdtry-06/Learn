#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
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
set<ll> se;
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll a[n];
        For(i, 0, n) cin >> a[i];
        For(i, 0, n)
        {
            while(a[i])
            {
                int x = a[i] % 10;
                a[i] /= 10;
                se.insert(x);
            }
        }
        for(auto x : se) cout << x << " ";
        cout << endl;
        se.clear();
    }
}
int main()
{
    // file();
    faster();
    solve();
}