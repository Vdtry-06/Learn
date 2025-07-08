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
ll a[1005][1005];
string s = "DR", t;
bool check = 0;
int x[2] = {1, 0};
int y[2] = {0, 1};
int n;
void eat()
{
    cin >> n;
    fr(i, 0, n)
    {
        fr(j, 0, n) cin >> a[i][j];
    }
}
void sleep(int i, int j)
{
    fr(k, 0, 2)
    {
        int i1 = i + x[k];
        int j1 = j + y[k];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1])
        {
            t += s[k];
            if(i1 == n - 1 && j1 == n - 1)
            {
                check = 1;
                cout << t << endl;
            }
            else sleep(i1, j1);
            t.pop_back();
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
    sleep(0, 0);
    if(!check) cout << -1;
}
