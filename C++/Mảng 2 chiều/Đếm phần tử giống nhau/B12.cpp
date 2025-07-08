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
int a[1005][1005];
void input()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n ;
        FOR(i, 1, n)
        {
            FOR(j, 1, n) cin >> a[i][j];
        }
        set<int> se;
        vector<int> v;
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                se.insert(a[i][j]);   
            }
            for(auto x : se) v.push_back(x);
            se.clear();
        }
        map<int, int> mp;
        for(auto x : v) mp[x]++;
        int d = 0;
        for(auto x : mp) 
        {
            if(x.se == n) d++;
        }
        cout << d << endl;
        v.clear();
        mp.clear();
    }
}
signed main()
{
    // file();
    faster();
    input();
}
