#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
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
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char a[1005][1005];
int s1, s2, t1, t2;
int n, m;
int ok;
void input()
{
    cin >> n >> m;
    FOR(i , 1, n)
    {
        FOR(j, 1, m) 
        {
            cin >> a[i][j];
            if(a[i][j] == 'S')
            {
                s1 = i; s2 = j;
            }
            else if(a[i][j] == 'T')
            {
                t1 = i; t2 = j;
            }
        }
    }
}
// prev : buoc lien trc
// cnt : so lan doi huong hien tai
void loang(int i, int j, int cnt,  int prev)
{
    if(cnt > 3) return;
    a[i][j] = '*';
    if(ok) return;
    if(i == t1 && j == t2) 
    {
        ok = 1;
        return;
    }
    FOR(k, 0, 3 && !ok)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != '*')
        {
            if(k == prev) loang(i1, j1, cnt, k);
            else loang(i1, j1, cnt + 1, k);
        }
    }
    a[i][j] = '.';
}
signed main()
{
    // file();
    faster();
    input();
    loang(s1, s2, 0, -1);
    if(ok) cout << "YES";
    else cout << "NO";
}
