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

    Bạn được cho một mảng gồm n số nguyên. 
    Ban đầu tất cả các số của mảng đều là 0. 
    Nhiệm vụ của bạn là xử lí 2 loại truy vấn:
    - Loại 1 có dạng 1 x y: Gán phần tử ở vị trí thứ x trong dãy thành số y
    - Loại 2 có dạng 2 l r: In ra tổng các phần tử trong đoạn từ l đến r
    Với mỗi truy vấn loại 2, hãy in ra câu trả lời trên một dòng.

*/
ll f[4 * MAX];
int a[MAX];
void update(int node, int l, int r, int i, int val){
    if(i < l || r < i) return;
    if(l == r) {
        f[node] = val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * node, l, mid, i, val);
    update(2 * node + 1, mid + 1, r, i, val);
    f[node] = f[2 * node] + f[2 * node + 1];
}
ll get(int node, int l, int r, int u, int v) {
    // [u [l, r] v]
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return f[node];
    int mid = l + r >> 1;
    ll g1 = get(2 * node, l, mid, u, v);
    ll g2 = get(2 * node + 1, mid + 1, r, u, v);
    return g1 + g2;
}
void solve(){
    int n, q;
    cin >> n >> q;
    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) update(1, 1, n, x, y);
        else cout << get(1, 1, n, x, y) << endl;
    }
}
signed main() {
    faster();
    file();
    solve();
}
