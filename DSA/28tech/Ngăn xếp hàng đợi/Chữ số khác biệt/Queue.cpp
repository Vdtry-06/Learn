#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
typedef priority_queue<int, vector<int>, greater<int>> qp_min;
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
vector<int> v;
bool check(string s)
{
    set<char> se;
    for(char x : s) 
    {
        if(se.count(x) == 1) return false;
        se.insert(x);
    }
    return true;
}
void init()
{
    queue<int> q;
    FOR(i, 1, 5) q.push(i);
    while(!q.empty())
    {
        int tmp = q.front(); q.pop();
        if(tmp > 1e5) break;
        v.push_back(tmp);
        FOR(i, 0, 5)
        {
            string s = to_string(tmp * 10 + i);
            if(check(s))
            {
                q.push(tmp * 10 + i);
            }
        }
    }
    
}
void input()
{
    init();
    int n;
    cin >> n;
    while(n--)
    {
        int l, r;
        cin >> l >> r;
        int d = 0;
        for(int x : v) 
        {
            if(x >= l && x <= r) d++;
            else if(x > r) break;
        }
        cout << d << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}