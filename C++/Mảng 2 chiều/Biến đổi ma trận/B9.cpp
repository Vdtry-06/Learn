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
int a[1005][1005];
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        For(i, 0, n)
        {
            For(j, 0, n) cin >> a[i][j];
        }
        int s = 0, s1 = 0;
        int mx = 0, mx1 = 0;
        int h = 0, c = 0;
        For(i, 0, n)
        {
            s = 0;
            For(j, 0, n) s += a[i][j];
            if(mx < s) 
            {
                mx = s;
                h = i;
            }
        }
        For(j, 0, n)
        {
            s1 = 0;
            For(i, 0, n) s1 += a[i][j];
            if(mx1 < s1) 
            {
                mx1 = s1;
                c = j;
            }
        }
        if(mx >= mx1)
        {
            int dis = 0;
            For(i, 0, n)
            {
                For(j, 0, n)
                {
                    dis += a[h][i] - a[i][j];
                }
            }
            cout << dis;
        }
        else 
        {
            int dis = 0;
            For(i, 0, n)
            {
                For(j, 0, n)
                {
                    dis += a[i][c] - a[i][j];
                }
            }
            cout << dis;
        }
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    input();
}
