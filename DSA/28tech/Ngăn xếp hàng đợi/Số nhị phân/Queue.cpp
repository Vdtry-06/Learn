#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
typedef pair<int, pair<int, int>> prr;
typedef pair<char, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fi first
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<int> v;
queue<string> q;
int n;
void input()
{
    cin >> n;
    q.push("1");
    FOR(i, 1, n)
    {
        string bin = q.front();
        cout << bin << " ";
        q.pop();
        q.push(bin + "0");
        q.push(bin + "1");
    }
}
signed main()
{
    // file();
    faster();
    input();
}