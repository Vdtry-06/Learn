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
map<string, int> mp;
vector<string> v, u, w;
void tach1(string &s)
{
    string tmp;
    stringstream ss(s);
    while(ss >> tmp)
    {
        v.push_back(tmp);
    }
}
void tach2(string &s)
{
    string tmp;
    stringstream ss(s);
    while(ss >> tmp)
    {
        u.push_back(tmp);
    }
}
bool cmp(string a, string b)
{
    return a < b;
}
void solve()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        tach1(a);
        tach2(b);
        for(string x : u) mp[x] = 1;
        for(string x : v)
        {
            if(mp[x] == 0)
            {
                w.push_back(x);
                mp[x] = 1;
            }
        } 
        sort(w.begin(), w.end(), cmp);
        for(string x : w) cout << x << " ";
        cout << endl;
        w.clear();
        v.clear();
        u.clear();
        mp.clear();
    }
}
int main()
{
    // file();
    faster();
    solve();
}