#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(ll i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(ll i = l; i < r; i++)
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
vector<pr> v;
map<int, int> mp;
bool cmp(pr a, pr b)
{
    if(a.se == b.se) return a.fi < b.fi;
    return a.se > b.se;
}
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        For(i, 0, n) 
        {
            cin >> a[i];
            b[i] = a[i];
            mp[i] = 1;
        }
        sort(a, a + n);
        For(i, 0, n)
        {
            auto it = upper_bound(a, a + n, b[i]);
            if(it - a == n) cout << "_ ";
            else cout << *it << " ";
        }
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}