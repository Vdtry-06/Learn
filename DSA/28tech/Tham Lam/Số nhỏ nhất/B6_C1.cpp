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
int s, d;
void input()
{
    cin >> s >> d;
    if(d * 9 < s)
    {
        cout << -1;
        return;
    } 
    if(s <= 9)
    {
        cout << 1;
        For(i, 0, d - 2) cout << 0;
        cout << s - 1;
        return;
    }
    int t = (s - 1) / 9;
    int r = (s - 1) % 9;
    vector<int> a;
    int cnt = 0;
    a.push_back(1);
    For(i, 0, d - 2 - t) a.push_back(0);
    a.push_back(r);
    For(i, 0, t) a.push_back(9);
    while(d != a.size())
    {
        a[1] += a[0];
        a.erase(a.begin());
    }
    for(int x : a) cout << x;
}
signed main()
{
    // file();
    faster();
    input();
    
}
