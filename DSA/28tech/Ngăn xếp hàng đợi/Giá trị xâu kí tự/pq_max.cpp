#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
typedef priority_queue<int, vector<int>, greater<int>> qp_min;
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

void input()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        int k;
        cin >> k >> s;
        map<char, int> mp;
        for(char x : s) mp[x]++;
        pq_max pq;
        for(auto x : mp) pq.push(x.se);
        if(k >= s.size()) cout << 0 << endl;
        else
        {
            while(k--)
            {
                ll x = pq.top(); pq.pop();
                pq.push(x - 1);
            }
            ll sum = 0;
            while(!pq.empty())
            {
                sum += 1ll * pq.top() * pq.top();
                pq.pop();
            }
            cout << sum << endl;
        }
        
    }
}
signed main()
{
    // file();
    faster();
    input();
}