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
int n;
ll k;
void input()
{
    cin >> n >> k;
}
ll dac(int n, ll k)
{
    if(n == 1) return 1;
    ll mid = pow(2, n - 1);
    if(mid == k) return n;
    else if(mid > k) return dac(n - 1, k);
    else return dac(n - 1, k - mid);
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << dac(n, k);
}