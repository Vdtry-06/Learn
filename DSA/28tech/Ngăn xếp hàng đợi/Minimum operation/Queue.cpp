#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
typedef priority_queue<int, vector<int>, greater<int>> pq_min;
typedef pair<int, pair<int, int>> prr;
typedef priority_queue<ll> pq_max;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
#define fi first 
#define se second
#define sze size()
#define endl '\n'
int solve(int s, int t)
{
    queue<pr> q;
    set<int> se;
    q.push({s, 0});
    while(!q.empty())
    {
        pr top = q.front(); q.pop();
        if(top.fi == t) return top.se;
        if(top.fi * 2 == t || top.fi - 1 == t) return top.se + 1;
        if(se.find(top.fi * 2) == se.end() && top.fi < t)
        {
            q.push({top.fi * 2, top.se + 1});
            se.insert(top.fi * 2);
        } 
        if(se.find(top.fi - 1) == se.end() && top.fi > 1)
        {
            q.push({top.fi - 1, top.se + 1});
            se.insert(top.fi - 1);
        } 
    }
    return -1;
}
void input()
{
    int n;
    cin >> n;
    while(n--)
    {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
