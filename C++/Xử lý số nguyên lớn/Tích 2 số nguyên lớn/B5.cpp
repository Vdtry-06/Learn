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

void solve(string &a, string &b, string &c)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = a.size();
    int m = b.size();
    c.resize(n + m, '0');
    For(i, 0, m)
    {
        int rem = 0;
        For(j, 0, n)
        {
            int x = (b[i] - '0') * (a[j] - '0') + rem + c[i + j] - '0';
            c[i + j] = x % 10 + '0';
            rem = x / 10;
        }
        if(rem > 0) c[i + n] = rem + '0';
    }
    while(c.size() > 1 && c.back() == '0') c.pop_back();
    FORD(i, c.size() - 1, 0) cout << c[i];
    cout << endl;
    c.clear();
}
void input()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string a, b, c;
        cin >> a >> b;
        solve(a, b, c);
    }
}
int main()
{
    // file();
    faster();
    input();
}
