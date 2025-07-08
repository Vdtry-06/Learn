#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i < r; i++)
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
queue<ull> q;
ull n;
int t;
void intt()
{
    q.push(1);
    while(!q.empty())
    {
        ull bin = q.front(); q.pop();
        if(bin > pow(2, 63)) break;
        v.push_back(bin);
        q.push(bin * 10);
        q.push(bin * 10 + 1);
    }
}
void input()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << lower_bound(v.begin(), v.end(), n) - v.begin() << endl;
    } 
}
signed main()
{
    // file();
    faster();
    intt();
    input();
}