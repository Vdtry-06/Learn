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
int n, m, s, t;
vector<pr> ke[MAX];
int pre[MAX];
void input(){
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        ke[x].push_back({y, w});
    }
}
void Dijkstra(int s, int t){
    // mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    // vector<bool> visited(n + 1, false);
    d[s] = 0;
    pre[s] = s;
    // hang doi uu tien luu {khoang cach, dinh}
    priority_queue<pr, vector<pr>, greater<pr>> q; 
    q.push({0, s});
    while(!q.empty()){
        // chon ra dinh co khoang cach tu s nho nhat
        pr top = q.top(); q.pop();
        int u = top.se;
        int kc = top.fi;
        // if(visited[u]) continue;
        // visited[u] = true;
        if(kc > d[u]) continue;// quan trong
        // relaxation: cap nhat khoang cach tu s cho den moi dinh ke voi u
        for(auto it : ke[u]){
            int v = it.fi;
            int w = it.se;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
                pre[v] = u; // trc v la u
            }
        }
    }
    cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
        // t = cha cua t
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
}
signed main()
{
    // file();
    faster();
    input();
    Dijkstra(s, t);
}