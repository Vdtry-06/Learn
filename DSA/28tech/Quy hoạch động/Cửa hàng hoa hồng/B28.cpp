#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define map map<int, int>
#define pr pair<int, ll>
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
int a[MAX], T[MAX], G[MAX];
int n, mx = 0;
void input()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}
void dp()
{
    T[1] = 1;
    FOR(i, 2, n)
    {
        if(a[i - 1] < a[i]) T[i] = T[i - 1] + 1;
        else T[i] = 1;
        mx = max(mx, T[i]);
    }
    G[n] = 1;
    FORD(i, n - 1, 1)
    {
        if(a[i] < a[i + 1]) G[i] = G[i + 1] + 1;
        else G[i] = 1;
    }
    FOR(i, 2, n - 1)
    {
        if(a[i - 1] < a[i + 1])
        {
            mx = max(mx, T[i - 1] + G[i + 1]);
        }
    }
    cout << mx;
}
signed main()
{
    // file();
    faster();
    input();
    dp();
}
