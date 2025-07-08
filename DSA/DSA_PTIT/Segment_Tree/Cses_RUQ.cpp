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
ll f[4 * MAX], lazy[4 * MAX];
int a[MAX];
void build(int id, int l, int r){
    if(l == r){
        f[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    f[id] = f[2 * id] + f[2 * id + 1];
}
void fix(int id, int l, int r){
    if(!lazy[id]) return;
    f[id] += lazy[id];
    if(l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, int val){
    fix(id, l, r);
    if(v < l || u > r) return;
    if(u <= l && r <= v){
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    f[id] = f[2 * id] + f[2 * id + 1];
}
ll get(int id, int l, int r, int k){
    fix(id, l, r);
    if(l == r) return f[id];
    int mid = l + r >> 1;
    if(k <= mid) return get(2 * id, l, mid, k);
    else return get(2 * id + 1, mid + 1, r, k);
}
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            int k;
            cin >> k;
            cout << get(1, 1, n, k) << endl;
        }
    }
}
signed main() {
    faster();
    // file();
    solve();
}
