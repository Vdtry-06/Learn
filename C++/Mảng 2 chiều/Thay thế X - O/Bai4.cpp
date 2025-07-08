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
char a[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;
void loang(int i, int j)
{
    a[i][j] = 1;
    For(k, 0, 4)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 && i1 < n && j1 >= 0 &&j < m && a[i1][j1] == 'O')
        {
            loang(i1, j1);
        }
    }
}
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
        For(i, 0, n)
        {
            if(a[i][0] == 'O') loang(i, 0);
            if(a[i][m - 1] == 'O') loang(i, m - 1);
        }
        For(j, 0, m)
        {
            if(a[0][j] == 'O') loang(0, j);
            if(a[n - 1][j] == 'O') loang(n - 1, j);
        }
        For(i, 0, n)
        {
            For(j, 0, m)
            {
                if(a[i][j] == 1) cout << "O";
                else cout << "X";
                cout << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    // file();
    faster();
    input();
}
