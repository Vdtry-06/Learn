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
int a[1005][1005];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int f[8] = {1, 2, 3, 4, 5, 6, 7, 8};
char t[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
int d = 0;
int loang(int x1, int y1, int x2, int y2) 
{
    queue<pr> q;
    q.push({x1, y1});
    a[x1][y1] = 0;
    while(!q.empty()) 
    {
        pr top = q.front(); q.pop();
        if (top.fi == x2 && top.se == y2) 
        {
            return a[top.fi][top.se];
        }
        for (int i = 0; i < 8; i++) 
        {
            int i1= top.fi + dx[i];
            int j1 = top.se + dy[i];
            if (i1 >= 0 && i1 < 8 && j1 >= 0 && j1 < 8 && a[i1][j1] == -1) 
            {
                a[i1][j1] = a[top.fi][top.se] + 1;
                q.push({i1, j1});
            }
        }
    }
    return -1;
}

int solve(string s) 
{
    return s[0] - 'a';
}

int solve2(string s) 
{
    return s[1] - '1';
}
void input()
{
    int n;
    cin >> n;
    while(n--)
    { 
        memset(a, -1, sizeof(a));
        string s1, s2;
        cin >> s1 >> s2;
        int x1 = solve(s1);
        int y1 = solve2(s1);
        int x2 = solve(s2);
        int y2 = solve2(s2);
        cout << loang(x1, y1, x2, y2) << endl;
    }
}
signed main()
{
    // file();
    faster();
    input();
}
