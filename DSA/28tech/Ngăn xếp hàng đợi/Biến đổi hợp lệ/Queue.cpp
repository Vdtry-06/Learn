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
const int N = 1e4;
bool check[N];
bool prime[N];
void sang()
{
    FOR(i, 0, N) prime[i] = 1;
    prime[0] = prime[1] = 0;
    FOR(i, 2, sqrt(N))
    {
        if(prime[i])
        {
            for(int j = i * i; j <= N; j += i) prime[j] = 0;
        }
    } 
}
int solve(int s, int t)
{
    sang();
    memset(check, false, sizeof(check));
    queue<pr> q;
    q.push({s, 0});
    while(!q.empty())
    {
        pr top = q.front(); q.pop();
        if(top.fi == t) return top.se;
        string ss = to_string(top.fi);
        FOR(i, 0, 3)
        {
            string st = ss;
            for(char c = '0'; c <= '9'; c++)
            {
                if(i == 0 && c == '0') continue;
                st[i] = c;
                int v = stoi(st);
                if(!check[v] && prime[v])
                {
                    check[v] = true;
                    q.push({v, top.se + 1});
                }
            }
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
