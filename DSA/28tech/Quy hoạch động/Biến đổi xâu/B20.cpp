#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define pr pair<int, int>
#define vi vector<int> 
#define vll vector<ll>
#define fi first
#define se second
#define sz size()
#define end '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int f[1005][1005];
string s1, s2;
void input()
{
    cin >> s1 >> s2;
}
void dp()
{
    int n = s1.sz;
    int m = s2.sz;
    s1 = '0' + s1;
    s2 = '0' + s2;
    FOR(j, 0, m) f[0][j] = j;
    FOR(i, 0, n) f[i][0] = i;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(s1[i] == s2[j])
            {
                f[i][j] = min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + 0});
                // f[i][j] = f[i - 1][j - 1];
            }
            else f[i][j] = min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + 1});
            // cout << i << " " << j << " " << f[i][j] << endl;
        }
    }
    cout << f[n][m];
}
signed main()
{
    //file();
    faster();
    input();
    dp();
}
