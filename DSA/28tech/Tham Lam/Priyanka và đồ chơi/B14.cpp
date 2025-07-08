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
int a[MAX], f[MAX];
int n;
void input()
{
    cin >> n;
    For(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int d = 0, l = 0;
    f[0] = 1;
    while(l < n && d < n)
    {
        if(a[l] + 4 >= a[d])
        {
            d++;  
            f[d] = f[d - 1] + 1;
        }
        else 
        {
            f[d] = 1;
            l = d;
        }
    }
    int cnt = 0;
    For(i, 0, d) if(f[i] == 1) cnt++;
    cout << cnt;
}
signed main()
{
    // file();
    faster();
    input();
    
}
