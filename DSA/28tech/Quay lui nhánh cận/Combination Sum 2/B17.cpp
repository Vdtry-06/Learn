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
int a[1005], f[1005];
vector<string> v;
int n, k;
void input()
{
    cin >> n >> k;
}
bool prime(int m)
{
    if(m < 2) return false;
    fr(i, 2, sqrt(m)) if(m % i == 0) return false;
    return true; 
}
void Try(int i, int bd, int sum)
{
    fr(j, bd, n)
    {
        if(prime(j))
        {
            if(sum + j <= n)
            {
                f[i] = j;
                if(i == k)
                {
                    if(sum + j == n)
                    {
                        string s;
                        fr(idx, 1, k)
                        {
                            s += to_string(f[idx]);
                            if(idx < k) s += " + ";
                        }
                        v.push_back(s);
                    }
                }
                else Try(i + 1, j + 1, sum + f[i]);
            }
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
    Try(1, 1, 0);
    if(v.empty())
    {
        cout << "NOT FOUND";
        return 0;
    }
    for(auto x : v) cout << x << endl;
}