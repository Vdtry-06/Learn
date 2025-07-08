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
int n;
int a[MAX];
void input()
{ 
    pq_min q;
    cin >> n;
    For(i, 0, n) 
    {
        cin >> a[i];
        q.push(a[i]);
    }
    ll ans = 0;
    while(q.size() > 1)
    {
        ll top1 = q.top(); q.pop();
        ll top2 = q.top(); q.pop();
        ans += top1 + top2;
        q.push(top1 + top2);
    }
    cout << ans;
}
signed main()
{
    // file();
    faster();
    input();
    
}
