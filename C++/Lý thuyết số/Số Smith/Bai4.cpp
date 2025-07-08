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
bool prime(int n)
{
    FOR(i, 2, sqrt(n)) if(n % i == 0) return false;
    return n > 1;
}
int sum(int n)
{
    int s = 0;
    while(n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int smith(int n)
{
    int s = 0;
    FOR(i, 2, sqrt(n))
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
                s += sum(i);
            }
        }
    }
    if(n > 1) s += sum(n);
    return s;
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(prime(n)) cout << "NO";
        else
        {
            if(sum(n) == smith(n)) cout << "YES";
            else cout << "NO";
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
