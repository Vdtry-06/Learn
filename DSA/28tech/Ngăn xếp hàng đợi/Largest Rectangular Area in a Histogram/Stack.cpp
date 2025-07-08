#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
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
int a[MAX], n;
ll get(int a[], int n)
{
    stack<int> st;
    st.push(-1);
    ll area = a[0];
    vector<int> left_sml(n, - 1), right_sml(n, n);
    FOR(i, 0, n)
    {
        while(!st.empty() && st.top() != -1 && a[st.top()] > a[i])
        {
            right_sml[st.top()] = i;
            st.pop();
        }
        if(i > 0 && a[i] == a[i - 1]) left_sml[i] = left_sml[i - 1];
        else left_sml[i] = st.top();
        st.push(i);
    }
    FOR(i, 0, n)
    {
        area = max(area,1ll * a[i] * (right_sml[i] - left_sml[i] - 1));
    }
    return area;
}
void input()
{
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    cout << get(a, n);
}
signed main()
{
    // file();
    faster();
    input();
}