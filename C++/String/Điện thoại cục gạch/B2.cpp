#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
string a[10];
bool check(string s)
{
    int n = s.size();
    For(i, 0, n / 2)
    {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}
void solve()
{
    a[2] = {"ABC"};
    a[3] = {"DEF"};
    a[4] = {"GHI"};
    a[5] = {"JKL"};
    a[6] = {"MNO"};
    a[7] = {"PQRS"};
    a[8] = {"TUV"};
    a[9] = {"WXYZ"};
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        cin >> s;
        For(i, 0, s.size())
        {
            if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
        }
        // cout << s;
        vector<int> v;
        For(i, 0, s.size())
        {
            For(j, 2, 10)
            {
                For(k, 0, a[j].size())
                {
                    if(s[i] == a[j][k]) v.push_back(j);
                }
            }
        }
        string u;
        for(int i : v) u += to_string(i);
        if(check(u)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}
