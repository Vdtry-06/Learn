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
ll n, k, cnt = 0;
ll a[MAX];
ll f[MAX];
void eat()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void sleep(int i, int bd, int sum)
{
    fr(j, bd, n + 1)
    {
        if(sum + a[j] <= k)
        {
            f[i] = a[j];
            if(sum + a[j] == k)
            {
                cout << "[";
                fr(r, 1, i + 1)
                {
                    cout << f[r];
                    if(r < i) cout << " ";
                    
                }
                cout << "]" << endl;
            }
            else sleep(i + 1, j + 1, sum + f[i]);
        }
    }
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eat();
    sort(a + 1, a + n + 1);
    sleep(1, 1, 0);
}
