#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
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
bool prime(int n)
{
    if(n < 2) return false;
    FOR(i, 2, sqrt(n)) if(n % i == 0) return false;
    return true;
}
bool check1(int n)
{
    while(n > 9)
    {
        if(n % 10 <= (n / 10) % 10) return 0;
        n /= 10;
    }
    return 1;
}
bool check2(int n)
{
    while(n > 9)
    {
        if(n % 10 >= (n / 10) % 10) return 0;
        n /= 10;
    }
    return 1;
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int d = 0;
        For(i, pow(10, n - 1), pow(10, n))
        {
            if((check1(i) || check2(i)) && prime(i)) d++;
        }
        cout << d << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}