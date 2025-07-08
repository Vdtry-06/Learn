#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<ll> 
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
map<char, ll> mp;
int n, k;
string s;
void input()
{
    int n;
    cin >> n;
    while(n--)
    {
        cin >> k >> s;
        pq_max q;
        for(char x : s) mp[x]++;
        for(auto x : mp) q.push(x.se);
        mp.clear();
        while(k > 0)
        {
            int top = q.top(); q.pop();
            top--;
            k--;
            q.push(max(top, 0));
        }
        ll ans = 0;
        while(!q.empty())
        {
            ans += 1ll * q.top() * q.top();
            q.pop();
        }
        cout << ans << endl;
    }
    
}
signed main()
{
    // file();
    faster();
    input();
    
}
