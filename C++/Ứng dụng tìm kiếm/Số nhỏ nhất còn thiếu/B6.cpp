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
bool binary_search(int n, int a[], int x)
{
    int l = 0, r = n - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] == x) return true;
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return false;
}
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        For(i, 0, n - 1) cin >> a[i];
        FOR(i, 1, n)
        {
            if(!binary_search(n, a, i))
            {
                cout << i;
                break;
            }
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