#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fi first
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int INF = 1e9;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
int n, m, s;
int mat[1005][1005];
// mat[i][j]: khoang cach duong di ngan nhat tu i -> j
void input(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) mat[i][j] = 0;
            else mat[i][j] = ING;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        mat[x][y] = w;
        mat[y][x] = w;
    }
}
void Floyd(int s){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    for(int j = 1; j <= n; j++) cout << mat[1][j] << " ";
}
signed main()
{
    // file();
    faster();
    input();
    Floyd(s);
}