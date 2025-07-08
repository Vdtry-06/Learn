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
stack<ll> st;
string s;
void input()
{
    cin >> s;
    reverse(s.begin(), s.end());
    for(char x : s)
    {
        if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '%')
        {
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            ll tmp;
            if(x == '+') tmp = a + b;
            else if(x == '-') tmp = a - b;
            else if(x == '*') tmp = a * b;
            else if(x == '/') tmp = a / b;
            else if(x == '%') tmp = a % b;
            else if(x == '^')
            {
                tmp = a;
                FOR(i, 0, b) tmp *= a; 
            }
            st.push(tmp);
        }
        else st.push((ll)(x - '0'));
    }
    cout << st.top();
}
signed main()
{
    // file();
    faster();
    input();
}