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
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], f[n], d = 0;
        memset(f, 0, sizeof(f));
        For(i, 0, n) cin >> a[i];
        sort(a, a + n);
        vector<int> v1, v2;
        int m = n;
        if(n % 2 != 0) n += 1;
        For(i, 0, n / 2) v1.push_back(a[i]);
        For(i, n / 2, m) v2.push_back(a[i]);
        For(i, 0, n / 2)
        {
            cout << v1[i] << " ";
            if(i < m - n / 2) cout << v2[i] << " ";
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
