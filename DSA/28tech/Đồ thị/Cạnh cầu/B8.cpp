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
vector<int> ke[MAX];
vector<pr> canh;
int a[1005][1005];
bool visited[MAX];
int n, m, s1 = -1, s2 = -1;
void input()
{
    cin >> n >> m;
    FOR(i, 0, m - 1)
    {
        int x, y;
        cin >> x >> y;
        canh.push_back({x, y});
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u)
{
    visited[u] = true;
    for(int v : ke[u])
    {
        //Neu xet phai canh muon loai bo thi khong xet
        if(u == s1 &&v == s2 || u == s2 && v == s1) continue;
        if(!visited[v]) 
        {
            DFS(v);
        }
    }
}
int dem() // so tplt
{
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    FOR(i, 1, n)
    {
        if(!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}
void canh_cau()
{
    int kq = 0;
    int cnt1 = dem();
    for(pr x : canh)
    {
        s1 = x.fi, s2 = x.se;
        int cnt2 = dem();
        if(cnt2 > cnt1) kq++;
    }
    cout << kq;
}
signed main()
{
    // file();
    faster();
    input();
    canh_cau();
}
