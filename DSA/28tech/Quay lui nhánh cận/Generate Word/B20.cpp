#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i < r; i++)
#define fr1(i, r, l) for(int i = r; i >= l; i--)
#define pr pair<int, int>
#define vt vector<int> 
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0}; 
char a[1005][1005];
bool check[1005][1005], ok = 0;
string s;
int n, m;
void input()
{
    cin >> n >> m;
    fr(i, 0, n) 
    {
        fr(j, 0, m) cin >> a[i][j];
    }
    cin >> s;
}
void Try(int i, int j, int cnt)
{
    if(cnt == s.size())
    {
        ok = 1;
    }
    check[i][j] = 1;
    fr(k, 0, 4)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(!check[i1][j1] && i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == s[cnt])
        {
            Try(i1, j1, cnt + 1);
        }
    }
    check[i][j] = 0;
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            if(a[i][j] == s[0])
            {
                Try(i, j, 1);
                if(ok) 
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    if(!ok) cout << "NO"; 
}