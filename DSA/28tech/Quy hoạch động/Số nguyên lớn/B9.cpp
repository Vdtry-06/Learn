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
int f[1005][1005], mx = 0;
string s1, s2;
void input()
{
    cin >> s1 >> s2;
}
void dp()
{
    fr(i, 1, s1.size())
    {
        fr(j, 1, s2.size())
        {
            if(s1[i - 1] == s2[j - 1])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else f[i][j] = max({f[i - 1][j], f[i][j - 1]});
            mx = max(mx, f[i][j]);
        }
    }
    cout << mx;
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
