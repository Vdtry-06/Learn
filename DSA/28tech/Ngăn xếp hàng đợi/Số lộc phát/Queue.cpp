#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
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
vector<ull> v;
void intt(int n)
{
    queue<ull> q;
    q.push(6);
    q.push(8);
    while(!q.empty())
    {
        ull tmp = q.front(); q.pop();
        if(to_string(tmp).size() > n) break;
        v.push_back(tmp);
        q.push(tmp * 10 + 6);
        q.push(tmp * 10 + 8);
    }
    sort(v.begin(), v.end(), greater<ull>());
    for(ull x : v) cout << x << " ";
    v.clear();
    cout << endl;
}
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        intt(n);
    }
}
signed main()
{
    // file();
    faster();
    input();
}