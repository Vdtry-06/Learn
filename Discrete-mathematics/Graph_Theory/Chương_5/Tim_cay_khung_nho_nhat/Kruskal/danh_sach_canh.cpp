#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

struct edge{
    int u, v;
    int w;
};

int n, m;
int parent[1005];
int sz[1005];
vector<edge> canh;

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edge e;
        e.u = x;
        e.v = y;
        e.w = z;
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void Kruskal(){
    // memset(canh, 0, sizeof(canh));
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;
        edge e = canh[i];
        if(Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d;
}

void solve(){
    init();
    make_set();
    Kruskal();
}

int main(){
    // file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
        canh.clear();
    }
}