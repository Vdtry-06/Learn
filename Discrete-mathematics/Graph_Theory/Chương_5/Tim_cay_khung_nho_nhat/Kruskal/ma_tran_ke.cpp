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
int a[1005][1005];

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
    if(a == b) return false;// khong the gop a, b voi nhau
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] != 0 && i < j){
                edge e;
                e.u = i;
                e.v = j;
                e.w = a[i][j];
                canh.push_back(e);
            }
        }
    }
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void Kruskal(){
    // tao cay khung cuc tieu rong
    vector<edge> mst;
    int d = 0;
    // sap xep danh sach thep chieu trong so tang dan
    sort(canh.begin(), canh.end(), cmp);
    // b3: lap
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;
        edge e = canh[i]; // chon canh e la canh nho nhat
        if(Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    // tra ve ket qua
    if(mst.size() != n - 1) cout << "DO THI KHONG LIEN THONG";
    else {
        cout << "MST: " << d << endl;
        for(auto x : mst) cout << x.u << " " << x.v << " " << x.w << endl;
    }
}

void solve(){
    init();
    make_set();
    Kruskal();
}

int main(){
    // file();
    faster();
    solve();
}