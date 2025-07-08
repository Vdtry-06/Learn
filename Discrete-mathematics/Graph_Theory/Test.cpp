#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
struct edge{
    int x, y, w;
};

int n, m, s;
vector<edge> ke;
int d[1005];

void input(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        ke.push_back({x, y, w});

    }
}

void Bellman_Ford(int s){
    fill(d + 1, d + n + 1, INF);
    d[s] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(edge it: ke){
            int x = it.x;
            int y = it.y;
            int w = it.w;
            if(d[x] < INF){
                d[y] = min(d[y], d[x] + w);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << d[i] << " ";
}
signed main()
{
    file();
    faster();
    input();
    cout << 1;
    // int t;
    // cin >> t;
    // while(t--){
        // Bellman_Ford(s);
    //     cout << endl;
    // } 
}