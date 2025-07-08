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
vector<int> a(MAX), f(MAX, -1);
stack<int> st;
int n;
void input()
{
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n)
    {
        while(!st.empty() && a[st.top()] < a[i])
        {
            f[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    FOR(i, 0, n) cout << f[i] << " ";
}
signed main()
{
    // file();
    faster();
    input();
}