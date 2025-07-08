#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i < r; i++)
#define fr1(i, r, l) for(int i = r - 1; i >= l; i--)
#define pr pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int x[2] = {1, 0};
int y[2] = {0, 1};
vector<string> v;
ll a[1005][1005];
ll f[1005][1005];
bool check = 0;
int n, m, cnt = 0;
void eat()
{
    cin >> n >> m;
    fr(i, 0, n)
    {
        fr(j, 0, m) cin >> a[i][j];
    }
}
void sleep(int i, int j)
{
    if(i == n - 1 && j == m - 1) 
    {
        cnt++;
        return;
    }
    if(i < n - 1) sleep(i + 1, j);
    if(j < m - 1) sleep(i, j + 1);
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eat();
    sleep(0, 0);
    cout << cnt;
}
