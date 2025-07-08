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
struct node{
    ll pre, sum;
    node (ll sum = 0, ll pre = 0) : sum(sum), pre(pre) {}
    static node base(ll x = 0) {
        return node(x, max(0LL, x));
    }
    static node merge(node &a, node &b){
        node res;
        res.pre = max(a.pre, a.sum + b.pre); // th1
        res.sum = a.sum + b.sum;
        return res;
    }
};
node f[4 * MAX];
int a[MAX];
void build(int id, int l, int r){
    if(l == r){
        f[id] = node :: base(a[l]);
        return;
    }
    int mid =  l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    f[id] = node :: merge(f[2 * id], f[2 * id + 1]);
}
void update(int id, int l, int r, int i, int val){
    if(i < l || i > r) return;
    if(l == r){
        f[id] = node :: base(val);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);
    f[id] = node :: merge(f[2 * id], f[2 * id + 1]);
}
node get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return node :: base();
    if(u <= l && r <= v) return f[id];
    int mid = l + r >> 1;
    node g1 = get(2 * id, l, mid, u, v);
    node g2 = get(2 * id + 1, mid + 1, r, u, v);
    return node :: merge(g1, g2);
}
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int i, val;
            cin >> i >> val;
            update(1, 1, n, i, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r).pre << endl;
        }
    }
}
signed main() {
    faster();
    // file();
    solve();
}
