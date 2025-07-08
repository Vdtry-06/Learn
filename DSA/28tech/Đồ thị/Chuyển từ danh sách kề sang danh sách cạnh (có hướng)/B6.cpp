#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define pr pair<int, ll>
#define vi vector<int> 
#define vll vector<ll>
#define fi first
#define se second
#define sz size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<int> a[MAX];
int parent[MAX];
bool visited[MAX];
int n, m;
vector<pr> v;
bool cmp(pr a, pr b)
{
    return a.se < b.se;
}
void input()
{
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp)
        {
            v.push_back({i, stoi(tmp)});
        }
        sort(v.begin(), v.end(), cmp);
        for(auto x : v) cout << x.fi << " " << x.se << endl;
        v.clear();
    }
}


signed main()
{
    // file();
    faster();
    input();
    
}
