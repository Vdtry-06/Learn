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
stack<string> st;
string s;
void input()
{
    cin >> s;
    for(char x : s)
    {
        if(isalpha(x))
        {
            st.push(string(1, x));
        }
        else
        {
            string kt1 = st.top(); st.pop();
            string kt2 = st.top(); st.pop();
            string tmp = '(' + kt2 + x + kt1 + ')';
            st.push(tmp);
        }
    }
    cout << st.top();
}
signed main()
{
    // file();
    faster();
    input();
}