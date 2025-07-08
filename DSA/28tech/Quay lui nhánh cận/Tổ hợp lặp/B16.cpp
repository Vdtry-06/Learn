#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i <= r; i++)
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
char a[1005], f[1005];
int n, k;
void input()
{
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
}

void Try(int i, int bd)
{
    fr(j, bd, n)
    {
        f[i] = a[j];
        if(i == k)
        {
            fr(idx, 1, k)
            {
                cout << f[idx];
            }
            cout << endl;
        }
        else Try(i + 1, j);
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
    sort(a + 1, a + n + 1);
    Try(1, 1);
}