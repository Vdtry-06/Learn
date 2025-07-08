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
void solve()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        if(n < m) 
        {
            swap(s1, s2);
            n = m;
        }
        else if(n == m && s1 < s2) swap(s1, s2);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while(s1.size() != s2.size()) s2 += "0";
        int f[n], rem = 0, d = 0;
        memset(f, 0, sizeof(f));
        For(i, 0, s1.size())
        {
            int a = s1[i] - '0';
            int b = s2[i] - '0';
            int x = a - b - rem;
            if(x < 0) 
            {
                x += 10;
                rem = 1;
            }
            else rem = 0;
            f[d++] = x;
        }
        if(rem > 0) f[d] -= rem;
        // while(f[d - 1] == 0 && d > 0) d--;
        FORD(i, d - 1, 0) cout << f[i];
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}
