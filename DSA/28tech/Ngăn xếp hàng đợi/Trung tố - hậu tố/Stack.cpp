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
vector<char> v;
stack<char> st;
string s;
void input()
{
    cin >> s;
}
int degree(char c)
{
    if(c == '^') return 5;
    if(c == '*' || c == '/') return 4;
    if(c == '+' || c == '-') return 3;
    return 2;
}
void stack_()
{
    string tmp = "";
    for(char x : s)
    {
        if(isalpha(x)) tmp += x;
        else if(x == '(') st.push(x);
        else if(x == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                tmp += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        {
            while(!st.empty() && degree(st.top()) >= degree(x))
            {
                tmp += st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty())
    {
        if(st.top() != '(') tmp += st.top();
        st.pop(); 
    }
    cout << tmp;
}
signed main()
{
    // file();
    faster();
    input();
    stack_();
}