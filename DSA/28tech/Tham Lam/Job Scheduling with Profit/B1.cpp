#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
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
int n;
struct job
{
    int id, dl, pf;
};
bool cmp(job a, job b)
{
    return a.pf > b.pf;
}
void input()
{
    cin >> n;
    job a[n];
    For(i, 0, n)
    {
        cin >> a[i].id >> a[i].dl >> a[i].pf;
    }
    sort(a, a + n, cmp);
    bool check[n] = {0};
    int s = 0;
    For(i, 0, n)
    {
        FORD(j, min(n, a[i].dl) - 1, 0)
        {
            if(!check[j])
            {
                s += a[i].pf;
                check[j] = 1;
                break;
            }
        }
    }
    cout << s;
}
signed main()
{
    // file();
    faster();
    input();
    
}
