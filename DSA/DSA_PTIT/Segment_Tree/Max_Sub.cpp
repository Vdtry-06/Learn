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
const int MAX = 5e4 + 5;

/*
    Tìm tổng lớn nhất trong đoạn [l, r]
*/

/*
    Phân tích bài toán:
        
        pre
        ------
        |---------------------|----------------------|
        l                    mid                     r

                  sum           pre
        ---------------------- ------
        |---------------------|----------------------|
        l                    mid                     r

                          suf   pre
                        ------ ------
        |---------------------|----------------------|
        l                    mid                     r

*/
struct node{
    int pre, suf, sum, max_sum;
    static node base() {return {-ING, -ING, 0, -ING};}
    // hàm hợp 2 nút con
    static node merge(node &a, node &b){
        node res;
        res.pre = max(a.pre, b.pre + a.sum);
        res.suf = max(b.suf, a.suf + b.sum);
        res.sum = a.sum + b.sum;
        res.max_sum = max(a.max_sum, b.max_sum);
        res.max_sum = max(res.max_sum, a.suf + b.pre);
        return res;
    }
};
node f[4 * MAX];
int a[MAX];
// tạo cây phân đoạn
void build(int idx, int l, int r){
    if(l == r){
        f[idx] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    f[idx] = node :: merge(f[2 * idx], f[2 * idx + 1]);
}
// hàm lấy giá trị
node get(int idx, int l, int r, int u, int v){
    // [u [l, r] v]
    if(v < l || u > r) return node :: base();
    if(u <= l && r <= v) return f[idx];
    int mid = l + r >> 1;
    node g1 = get(2 * idx, l, mid, u, v);
    node g2 = get(2 * idx + 1, mid + 1, r, u, v);
    return node :: merge(g1, g2);
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    int q; cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r).max_sum << endl;
    }
}
signed main() {
    faster();
    // file();
    solve();
}
