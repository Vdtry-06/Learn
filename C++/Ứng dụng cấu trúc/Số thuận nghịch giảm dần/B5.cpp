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
#define pr pair<string, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
bool check(string s)
{
    int n = s.size();
    if(n > 1)
    {
        For(i, 0, n / 2)
        {
            if(s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
    return false;
}
bool cmp(pr a, pr b)
{
    if(a.fi.size() == b.fi.size())
    {
        return a.fi > b.fi;
    }
    return a.fi.size() > b.fi.size();
}
void solve()
{
    string s;
    vector<pr> v;
    map<string, int> mp;
    while(cin >> s) 
    {
        if(check(s)) mp[s]++;
    }
    for(auto x : mp) v.push_back({x.fi, x.se});
    sort(v.begin(), v.end(), cmp);
    For(i, 0, v.size())
    {
        cout << v[i].fi << " " << v[i].se << endl;
    }
}
signed main()
{
    // file();
    faster();
    solve();
}