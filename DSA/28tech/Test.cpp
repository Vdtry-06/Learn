#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
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
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int a[1005][1005];
bool check[1005][1005];
int n, m;
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        For(i, 0, n)
        {
            For(j, 0, m) cin >> a[i][j];
        }
        int s = 0, d = 0;
        memset(check, false, sizeof(check));
        For(i, 0, n)
        {
            For(j, 0, m)
            {
                if(a[i][j] == -1)
                {
                    check[i][j] = 1;
                    For(k, 0, 8)
                    {
                        int i1 = i + dx[k];
                        int j1 = j + dy[k];
                        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] >= 0 && !check[i1][j1])
                        {
                            s += a[i1][j1];
                            check[i1][j1] = 1; 
                        }
                    }
                }
            }
        }
        cout << s;
    }
}
signed main()
{
    file();
    faster();
    input();
}
