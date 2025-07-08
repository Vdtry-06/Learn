#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
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
int a[1005][1005], n, m;
int hcn(int b[])
{
    stack<int> st;
    int i = 0, mx = 0;
    while(i < m)
    {
        if(st.empty() || b[i] >= b[st.top()]) st.push(i++);
        else 
        {
            int top = st.top();
            st.pop();
            if(st.empty()) mx = max(mx, i * b[top]);
            else mx = max(mx, b[top] * (i - st.top() - 1));
        }
    }
    while(!st.empty())
    {
        int top = st.top();
        st.pop();
        if(st.empty()) mx = max(mx, i * b[top]);
        else mx = max(mx, b[top] * (i - st.top() - 1));
    }
    return mx;
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        For(i, 0, n) 
        {
            For(j, 0, m) cin >> a[i][j];
        }
        int b[n][m];
        For(i, 0, n)
        {
            For(j, 0, m)
            {
                if(a[i][j] == 0) a[i][j] = 0;
                else 
                {
                    if(i == 0) a[i][j] = a[i][j];
                    else a[i][j] += a[i - 1][j];
                }
            }
           
        } 
        int res = 0;
        For(i, 0, n)
        {
            sort(a[i], a[i] + m);
            res = max(res, hcn(a[i]));
        }
        cout << res << endl;
    }
}
int main()
{
    // file();
    faster();
    input();
}
