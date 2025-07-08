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
int n, a[1005];
bool check[1005];
vector<vt> v;
int f[1005];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
void Try(int i, int bd, int sum)
{
    fr(j, bd, n)
    {
        f[i] = a[j];
        if((sum + a[j]) % 2 != 0)
        {
            vector<int> tmp(f + 1, f + i + 1);
            v.push_back(tmp);
        }
        if(i < n) Try(i + 1, j + 1, sum + f[i]);
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
    Try(1, 1, 0);
    if(v.empty()) 
    {
        cout << "NOT FOUND";
        return 0;
    }
    sort(v.begin(), v.end());
    for(auto x : v)
    {
        for(auto it : x) cout << it << " ";
        cout << endl;
    }
}