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
void input()
{
    cin >> s;
}
void Try(int i, string cur)
{
    if(i == s.size())
    {
        cout << cur << endl;
        return;
    }
    if(isalpha(s[i]))
    {
        Try(i + 1, cur + (char)(toupper(s[i])));
        Try(i + 1, cur + (char)(tolower(s[i])));
    }
    else Try(i + 1, cur + (char)(s[i]));
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