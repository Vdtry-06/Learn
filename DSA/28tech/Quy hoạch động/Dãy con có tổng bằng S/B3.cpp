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
int a[MAX], f[MAX];
int n, s;
void input()
{
    cin >> n >> s;
    fr(i, 0, n) cin >> a[i];
}
void dp()
{
    f[0] = 1;
    fr(i, 0, n)
    {
        fr1(j, s, a[i])
        {
            if(f[j - a[i]]) f[j] = 1;
        }
    }
    cout << f[s];
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    dp();
}
