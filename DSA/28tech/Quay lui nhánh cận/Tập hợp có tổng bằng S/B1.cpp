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
ll n, s, k, cnt = 0;
ll a[MAX];
void eat()
{
    cin >> n >> k >> s;
}
void code()
{
    int sum = 0;
    fr(i, 1, k + 1)
    {
        sum += a[i];
    }
    if(sum == s) cnt++;
}
void sleep(int i)
{
    fr(j, a[i - 1] + 1, n - k + i + 1)
    {
        a[i] = j;
        if(i == k)
        {
            code();
        }
        else sleep(i + 1);
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
    sleep(1);
    cout << cnt;
}
