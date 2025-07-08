#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define pq_max priority_queue<int>
#define pr pair<ll, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF = 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
int f[4 * MAX];
int a[MAX];

void build(int node, int l, int r){ // xây dựng cây phân đoạn
    if(l == r) {
        f[node] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    f[node] = min(f[2 * node], f[2 * node + 1]);
}

void update(int node, int l, int r, int i, int val){ // gán val cho vị trí i 
    if(i < l || i > r) return; // i nằm ngoài [l, r]
    if(l == r){ // đoạn gồm 1 phần tử không có node con
        f[node] = val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * node, l, mid, i, val);
    update(2 * node + 1, mid + 1, r, i, val);
    f[node] = min(f[2 * node], f[2 * node + 1]);
}

int get(int node, int l, int r, int u, int v){ // hàm lấy giá trị
    // [u <= l <= r <= v] 
    if(l > v || r < u) return ING;
    if(l >= u && v >= r) return f[node];
    int mid = l + r >> 1;
    int g1 = get(2 * node, l, mid, u, v);
    int g2 = get(2 * node + 1, mid + 1, r, u, v);
    return min(g1, g2); // trả về giá trị min theo 2 node con
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) update(1, 1, n, x, y);
        else cout << get(1, 1, n, x, y) << endl;
    }
}
signed main() {
    faster();
    // file();
    solve();
}
/*
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 2 3
2 1 4
*/