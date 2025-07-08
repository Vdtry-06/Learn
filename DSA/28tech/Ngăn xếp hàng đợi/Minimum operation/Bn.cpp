#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
typedef priority_queue<int, vector<int>, greater<int>> pq_min;
typedef pair<int, pair<int, int>> prr;
typedef priority_queue<ll> pq_max;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
#define fi first 
#define se second
#define sze size()
#define endl '\n'
pq_min pq;
int n, s, t;
void input()
{
    cin >> n;
    while(n--)
    {
        cin >> s >> t;
        int tmp = 0;
        while(s != t)
        {
            if(s < t)
            {
                if(t % 2 == 0) t /= 2;
                else t++;
            }
            else t++;
            tmp++;
        }
        cout << tmp << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
