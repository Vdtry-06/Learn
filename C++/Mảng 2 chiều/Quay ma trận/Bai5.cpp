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
int a[1005][1005];
int b[1005][1005];
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        FOR(i, 1, n) 
        {
            FOR(j, 1, m) cin >> a[i][j];
        }
        int h1 = 1, hn = n, c1 = 1, cn = m;
        while(h1 < hn && c1 < cn)
        {
            int per = a[h1 + 1][c1];
            FOR(i, c1, cn) 
            {
                int tmp = a[h1][i];
                a[h1][i] = per;
                per = tmp;
            }
            h1++;
            FOR(i, h1, hn) 
            {
                int tmp = a[i][cn];
                a[i][cn] = per;
                per = tmp;
            }
            cn--;
            if(h1 <= hn)
            {
                FORD(i, cn, c1)
                {
                    int tmp = a[hn][i];
                    a[hn][i] = per;
                    per = tmp;
                }
                hn--;
            }
            if(c1 <= cn)
            {
                 FORD(i, hn, h1)
                {
                    int tmp = a[i][c1];
                    a[i][c1] = per;
                    per = tmp;
                }
                c1++;
            }
        }
        FOR(i, 1, n)
        {
            FOR(j, 1, m) cout << a[i][j] << " ";
            // cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    input();
}
