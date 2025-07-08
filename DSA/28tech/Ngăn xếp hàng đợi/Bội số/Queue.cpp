#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i < r; i++)
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
int n, t;
void input()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        queue<string> q;
        q.push("8");
        while(1)
        {
            string bin = q.front();
            q.pop();
            if(stoll(bin) % n == 0)
            {
                cout << bin << endl;
                break;
            }
            q.push(bin + "0");
            q.push(bin + "8");
        }
    } 
}
signed main()
{
    // file();
    faster();
    input();
}