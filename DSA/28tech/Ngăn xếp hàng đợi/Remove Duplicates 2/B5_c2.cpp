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
int k, cnt = 0, d = 0;
vector<char> v;
stack<pr> st;
string s;
void input()
{
    cin >> s >> k;
    for(char x : s)
    {
        if(!st.empty() && st.top().fi == x)
        {
            st.top().se++;
            if(st.top().se == k) st.pop();
        }
        else st.push({x, 1});
    }
    if(st.empty())
    {
        cout << "EMPTY";
        return;
    }
    string tmp = "";
    while(!st.empty())
    {
        FOR(i, 0, st.top().se) v.push_back(st.top().fi);
        st.pop();
    }
    reverse(v.begin(), v.end());
    for(char x : v) cout << x;
}
signed main()
{
    // file();
    faster();
    input();
}