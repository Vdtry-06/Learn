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
int f[MAX];
int n;
void input()
{
    cin >> n;
}
int dp(int n)
{
    if(n == 0) return 0;
    if(f[n]) return f[n]; 
    int tmp = n, res = 1e9;
    while(tmp)
    {
        int r = tmp % 10;
        tmp /= 10;
        if(r != 0) res = min(res, dp(n - r) + 1);
    }
    f[n] = res;
    return res;
}
signed main()
{
    // file();
    faster();
    input();
    cout << dp(n);
}
