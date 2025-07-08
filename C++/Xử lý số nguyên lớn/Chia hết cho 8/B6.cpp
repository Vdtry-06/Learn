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
const int MAX = 1e7 + 5;
int ch_8(string s, int m)
{
    int d = 0;
    For(i, 0, s.size())
    {
        int sum = 0;
        For(j, i, s.size())
        {
            sum = sum * 10 + s[j] - '0';
            sum %= m;
            if(sum == 0) d++;
        }
    } 
    return d;
}
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << ch_8(s, 8) - ch_8(s, 24) << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}