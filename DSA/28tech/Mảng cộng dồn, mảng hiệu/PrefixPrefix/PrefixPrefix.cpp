#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 5;
struct tv
{
    ll l, r, d, vt;
};

vector<tv> v;
ll n, m, k;
ll x, y;
ll f[MAX], a[MAX];

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++)
    {
        tv tmp;
        cin >> tmp.l >> tmp.r >> tmp.d;
        v.push_back(tmp);
    }
    while(k--)
    {
        cin >> x >> y;
        x--; y--;
        for(int i = x; i <= y; i++)
        {
            f[v[i].l] += v[i].d;
            f[v[i].r + 1] -= v[i].d;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
        a[i - 1] += f[i];
        cout << a[i - 1] << " ";
    }
}