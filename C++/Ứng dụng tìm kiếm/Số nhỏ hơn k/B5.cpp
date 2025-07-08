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
int a[MAX];
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        For(i, 0, n) cin >> a[i];
        int d1 = 0, d2 = 0;
        For(i, 0, n) 
            if(a[i] <= k) d1++;
        For(i, 0, d1)
            if(a[i] > k) d2++;
        int d = d2, i = 0, j = d1;
        while(j < n)
        {
            if(a[i] > k) d2--;
            if(a[j] > k) d2++;
            d = min(d, d2);
            i++; j++;
        }
        cout << d << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}