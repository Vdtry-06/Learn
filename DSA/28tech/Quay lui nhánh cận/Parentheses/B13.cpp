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
char x[3] = {'(', '[', '{'};
char y[3] = {')', ']', '}'};
vector<string> v;
int n, k, a[1005];
char f[1005];
string s;

void input()
{
    cin >> n;
}
bool check(string s)
{
    stack<char> st;
    for(char x : s)
    {
        if(st.empty()) st.push(x);
        else if((st.top() == '(' && x == ')') 
        || (st.top() == '[' && x == ']')
        || (st.top() == '{' && x == '}'))
        {
            st.pop();
        }
        else st.push(x);
    }
    return st.empty();
}
void Try(int cnt, int open, int close, string cur)
{
    if(cnt == n)
    {
        if(check(cur)) v.push_back(cur);
        return;
    }
    if(open < n) 
    {
        fr(i, 0, 3) Try(cnt + 1, open + 1, close, cur + x[i]);
    }
    if(close < open)
    {
        fr(i, 0, 3) Try(cnt + 1, open, close + 1, cur + y[i]);
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
    if(n & 1) 
    {
        cout << "NOT FOUND";
        return 0;
    }
    Try(0, 0, 0, "");
    sort(v.begin(), v.end());
    if(v.empty()) 
    {
        cout <<"NOT FOUND";
        return 0;
    }
    for(auto x : v) cout << x << " ";
}