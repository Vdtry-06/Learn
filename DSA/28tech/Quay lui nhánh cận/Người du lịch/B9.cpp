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
int n, k, a[1005][1005], mi = INT_MAX;
int f[1005], s = 0, cmi = INT_MAX;
bool visited[1005];

void input()
{
    cin >> n;
    fr(i, 1, n)
    {
        fr(j, 1, n) 
        {
            cin >> a[i][j];
            cmi = min(cmi, a[i][j]);
        }
    }
}
void Try(int i, int cnt, int sum)
{
    if(cnt == n)
    {
        mi = min(mi, sum + a[i][1]);
        return;
    }
    fr(j, 1, n)
    {
        if(!visited[j])
        {
            visited[j] = true;
            if(sum + (n - j) * cmi < mi) Try(j, cnt + 1, sum + a[i][j]);
            visited[j] = false;
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
    visited[1] = true;
    Try(1, 1, 0);
    cout << mi;
}