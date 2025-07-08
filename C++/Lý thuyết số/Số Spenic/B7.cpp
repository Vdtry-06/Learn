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
    vector<int> v;
    FOR(i, 2, sqrt(n))
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
                v.push_back(i);
            }
            
        }
    }
    if(n > 1) v.push_back(n);
    set<int> se;
    for(int x : v) se.insert(x);
    return se.size() == v.size() && v.size() == 3;
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(prime(n)) cout << 1;
        else cout << 0;
        cout << endl;
    }
    
}
signed main()
{
    // file();
    faster();
    input();
}