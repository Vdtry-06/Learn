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
stack<char> st;
int cnt1 = 0,cnt2 = 0, d = 0;
string s;
bool input()
{
    FOR(i, 0, s.size())
    {
        if(s[i] == ')')
        {
            bool check = true;
            while(!st.empty() && st.top() != '(')
            {
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') check = false;
                st.pop();
            }
            if(check) return true;
            st.pop();
        }
        else st.push(s[i]);
    }
    return false;
}
signed main()
{
    // file();
    faster();
    cin >> s;
    if(input()) cout << "YES";
    else cout << "NO";
}