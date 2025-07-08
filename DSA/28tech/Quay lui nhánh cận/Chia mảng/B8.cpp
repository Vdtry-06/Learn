#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i <= r; i++)
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
int n, k, a[1005], s;
bool check = 0;
int f[1005];

void Try(int i,int bd, int sum)
{
    if(check) return;
    fr(j, bd, n)
    {
        if(sum + a[j] <= s)
        {
            f[i] = a[j];
            if(sum + a[j] == s)
            {
                check = 1;
            }
            else Try(i + 1, j + 1, sum + f[i]);
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
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
    s = 0;
    fr(i, 1, n) s += a[i];
    if(s % k != 0) 
    {
        cout << 0;
        return 0;
    }
    s /= k;
    Try(1, 1, 0);
    if(check) cout << 1;
    else cout << 0;
}