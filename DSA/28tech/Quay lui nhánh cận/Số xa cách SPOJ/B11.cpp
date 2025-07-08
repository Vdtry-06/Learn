#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i <= r; i++)
#define fr1(i, r, l) for(int i = r; i >= l; i--)
#define pr pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int n, k, a[1005];
int f[1005];
bool check[1005];
void input()
{
    cin >> n;
}
bool ck()
{
    fr(i, 2, n)
    {
        if(abs(f[i] - f[i - 1]) <= 1) return false;
    }
    return true;
}
void Try(int i)
{
    fr(j, 1, n)
    {
        if(check[j] == 0)
        {
            check[j] = 1;
            f[i] = j;
            if(i == n)
            {
                if(ck())
                {
                    fr(idx, 1, n) cout << f[idx];
                    cout << endl;
                }
            }
            else Try(i + 1);
            check[j] = 0;
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
    input();
    Try(1);
}