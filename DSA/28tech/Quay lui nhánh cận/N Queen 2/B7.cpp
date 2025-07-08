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
int cot[1005], dcx[1005], dcn[1005];
int f[1005], cnt = 0, n, mx = 0, s;
int a[1005][1005];
void input()
{
    fr(i, 1, n + 1)
    {
        fr(j, 1, n + 1) cin >> a[i][j];
    }
    fr(i, 1, 100) 
    {
        cot[i] = dcx[i] = dcn[i] = 1;
    }
}
void xuly()
{
    s = 0;
    fr(i, 1, n + 1) s += a[i][f[i]]; 
    mx = max(mx, s);
}
void Try(int i)
{
    fr(j, 1, n + 1)
    {
        if(cot[j] == 1 && dcx[i - j + n] == 1 && dcn[i + j - 1] == 1)
        {
            cot[j] = dcx[i - j + n] = dcn[i + j - 1] = 0;
            f[i] = j;
            if(i == n) xuly();
            else Try(i + 1);
            cot[j] = dcx[i - j + n] = dcn[i + j - 1] = 1;
            
        }
    }
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = 8;
    input();
    Try(1);
    cout << mx;
}