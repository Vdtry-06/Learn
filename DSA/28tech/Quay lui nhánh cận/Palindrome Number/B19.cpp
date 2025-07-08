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
string s;
int n;
void input()
{
    cin >> s;
    n = s.size();
}
bool check(string st)
{
    int m = st.size();
    fr(i, 0, m / 2)
    {
        if(st[i] != st[m - i - 1]) return false;
    }
    return true;
}
void Try(int i, string cur)
{
    if(i == n) 
    {
        cout << cur << endl;
        return;
    }
    fr(j, i, n)
    {
        string tmp = s.substr(i, j - i + 1);
        if(check(tmp))
        {
            if(i == 0) Try(j + 1, tmp);
            else Try(j + 1, cur + " " + tmp);
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
    Try(0, "");
}