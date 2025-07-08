#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int n, c[100][100], res = INT_MAX, sum = 0;
int x[100];
bool visited[100];
int cmin = INT_MAX;

void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(!visited[j])
        {
            x[i] = j;
            visited[j] = true;
            sum += c[x[i - 1]][x[i]];
            if(i == n)
            {
                res = min(res, sum + c[x[n]][1]);
            }
            else if(sum + (n - i) * cmin < res) Try(i + 1);
            visited[j] = false;
            sum -= c[x[i - 1]][x[i]];
        }
    }
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if(c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    }
    x[1] = 1;
    visited[1] = true;
    Try(2);
    cout << res;
}
