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
const int MAX = 1e5 + 5;

/*
    Bạn được cho một mảng gồm n số nguyên. Nhiệm vụ của bạn là xử lí 2 loại truy vấn:
    -Loại 1 có dạng : Tăng giá trị của các phần tử từ vị trí thứ x đến vị trí thứ y
    trong dãy lên val đơn vị
    -Loại 2 có dạng : In ra phần tử lớn nhất của dãy từ phần tử thứ x đến phần tử thứ y
    Với mỗi truy vấn loại 2, hãy in ra câu trả lời trên một dòng.

*/
/*
    Phân tích bài toán:
        Ta dùng kĩ thuật Lazy Propagation:
            st[id] += lazy[id] - cập nhật giá trị nút id theo lazy[id].
            Nếu nút id không phải là nút lá thì ta đẩy giá trị lazy xuống các con của nó :
            lazy[2 * id] += lazy[id]
            lazy[2 * id + 1] += lazy[id]
            lazy[id] = 0 - chú ý ta cần phải thực hiện thao tác này, nếu không mỗi phần tử của dãy sẽ bị tăng lên nhiều lần, do ta đẩy xuống nhiều lần.
*/

ll f[4 * MAX], lazy[4 * MAX];
int a[MAX];
void build(int id, int l, int r){
    if(l == r) {
        f[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    f[id] = max(f[2 * id], f[2 * id + 1]);
}
// Cập nhật node đang xét và đẩy giá trị lazy xuống các nút con
void push(int id, int l, int r){
    if(!lazy[id]) return;
    f[id] += lazy[id]; // cập nhật giá trị node hiện tại

    if(l != r){ // id != node lá đẩy giá trị lazy xuống các con
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0; // xóa dấu cập nhật cho node hiện tại
}
void update(int id, int l, int r, int u, int v, int val){
    push(id, l, r);
    if(l > v || r < u) return;
    if(u <= l && r <= v){
        lazy[id] += val;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    f[id] = max(f[2 * id], f[2 * id + 1]);
}
ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if(l > v || r < u) return -ING;
    if(u <= l && r <= v) return f[id];
    int mid = l + r >> 1;
    ll g1 = get(2 * id, l, mid, u, v);
    ll g2 = get(2 * id + 1, mid + 1, r, u, v);
    return max(g1, g2);
}
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
}
signed main() {
    faster();
    // file();
    solve();
}
