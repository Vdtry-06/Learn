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
int n, k, a[1005], mi = INT_MAX;
int f[1005], cnt = 0;
bool visited[1005];
vector<string> v;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
void Try(int i, int bd)
{
    fr(j, bd, n)
    {
        if(a[j] > f[i - 1])
        {
            f[i] = a[j]; 
            if(i >= 2) 
            {
                string s;
                fr(idx, 1, i)
                {
                    s += to_string(f[idx]);
                    if(idx < i) s += ' ';
                }
                v.push_back(s);
            }
            if(i < n) Try(i + 1, j + 1);
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
    Try(1, 1);
    sort(v.begin(), v.end());
    for(auto x : v) cout << x << endl;
}