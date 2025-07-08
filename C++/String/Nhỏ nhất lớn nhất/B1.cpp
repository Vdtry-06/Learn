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
void solve()
{
    int m, s;
    cin >> m >> s;
    if(m == 1 && s == 0) {cout << "0 0"; return;} 
    if(m * 9 < s || s == 0) {cout << "-1 -1"; return;}
    int k = s / 9;
    int h = k;
    if(k >= 1)
    {
        int x = s - k * 9;
        if(x == 0 || x == 1) 
        {
            x = s - (k - 1) * 9;
            k--;
        }
        if(k < m - 1)
        {
            cout << 1;
            For(i, 0, m - k - 2) cout << 0;
            cout << x - 1;
            For(i, 0, k) cout << 9;
        }
        else 
        {
            cout << x;
            For(i, 0, k) cout << 9;
        }
        cout << " ";
        For(i, 0, h) cout << 9;
        if(m > h) cout << s - h * 9;
        For(i, 0, m - h - 1) cout << 0;
        return;
    }
    if(m == 1) cout << s;
    else 
    {
        cout << 1;
        For(i, 0, m - 2) cout << 0;
        cout << s - 1;
    }
    cout << " ";
    cout << s;
    For(i, 0, m - 1) cout << 0;
}
int main()
{
    // file();
    faster();
    solve();
}