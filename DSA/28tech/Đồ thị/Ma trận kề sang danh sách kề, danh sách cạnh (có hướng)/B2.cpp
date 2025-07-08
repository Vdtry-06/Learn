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
vector<int> ke[1005];
int a[1005][1005];
vector<pr> v;
int n;
void input()
{
    cin >> n;
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
            {
                v.push_back({i, j});
            }
        }
    }
    for(auto x : v)
    {
        ke[x.fi].push_back(x.se);
        cout << x.fi << " " << x.se << endl;
    }
    v.clear();
    cout << endl;
    FOR(i, 1, n)
    {
        cout << i <<" : ";
        for(auto x : ke[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}


signed main()
{
    // file();
    faster();
    input();
    
}
