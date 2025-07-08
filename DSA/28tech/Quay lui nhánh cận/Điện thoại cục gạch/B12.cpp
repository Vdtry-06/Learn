#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i < r; i++)
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
vector<string> v;
int n, k, a[1005];
char f[1005];
bool check[1005];
string val[10], s;
void xuly()
{
    val[2] = {"abc"};
    val[3] = {"def"};
    val[4] = {"ghi"};
    val[5] = {"jkl"};
    val[6] = {"mno"};
    val[7] = {"pqrs"};
    val[8] = {"tuv"};
    val[9] = {"wxyz"};
}
void input()
{
    cin >> s;
    sort(s.begin(), s.end());
}
void Try(int i)
{
    for(char c : val[s[i] - '0'])
    {
        f[i] = c;
        if(i == s.size() - 1)
        {
            fr(idx, 0, s.size())
            {
                cout << f[idx];
            }
            cout << " ";
        }
        else Try(i + 1);
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
    xuly();
    Try(0);
}