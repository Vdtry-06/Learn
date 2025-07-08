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
int solve(int n)
{
    queue<pr> q;
    set<ll> se;
    q.push({n, 0});
    while(!q.empty())
    {
        pr top = q.front(); q.pop();
        if(top.fi == 1) return top.se;
        if(top.fi - 1 == 1) return top.se + 1;
        if(se.find(top.fi - 1) == se.end() && top.fi > 1)
        {
            q.push({top.fi - 1, top.se + 1});
            se.insert(top.fi - 1);
        }
        FOR(i, 2, sqrt(top.fi))
        {
            if(top.fi % i == 0)
            {
                int mx = max(top.fi / i, i);
                if(se.find(mx) == se.end())
                {
                    q.push({mx, top.se + 1});
                    se.insert(mx);
                }
            }
        }
    }
    return -1;
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
