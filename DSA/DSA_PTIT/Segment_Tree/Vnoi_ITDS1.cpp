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
    Cho một dãy số có N số. Bạn cần xử lí 2 loại truy vấn:
    Truy vấn loại 1 có dạng 1 i v, ta đổi số ở vị trí i thành v.
    Truy vấn loại 2 có dạng 2 L R k, ta cần in ra số nhỏ nhất mà lớn hơn bằng k trong khoảng [L..R].

*/

/*
    Phân tích bài toán:
        Trong bài toán này, mỗi nút của cây phân đoạn là một multiset chứa các phần tử 
        trong đoạn mà nó quản lí. Khi đó, để hợp nhất các nút con, ta chỉ cần insert 
        toàn bộ phần tử của cả 2 nút con vào nút cha.

        - Với truy vấn loại 1, khi cập nhật một nút, ta không cần phải insert lại 
        toàn bộ phần tử của cả  nút con, mà chỉ cần xóa đi một giá trị cũ 
        trong multiset và chèn thêm giá trị mới.

        - Với truy vấn loại 2, ta thực hiện tương tự như thao tác lấy giá trị. 
        Tuy nhiên, mỗi khi xét đến nút mà đoạn nó quản lí nằm hoàn toàn bên trong 
        đoạn cần truy vấn (trường hợp cơ sở), ta sử dụng hàm lower_bound để trả ra 
        giá trị nhỏ nhất mà vẫn lớn hơn hoặc bằng k trong multiset của nút đó.

*/

multiset<int> f[4 * MAX];
int a[MAX];
void build(int idx, int l, int r){
    if(l == r){
        f[idx].insert(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    f[idx] = f[2 * idx + 1];
    for(int x : f[2 * idx]) f[idx].insert(x); 
}
void update(int idx, int l, int r, int i, int old, int val){
    if(i < l || r < i) return;
    if(l == r){
        f[idx].clear();
        f[idx].insert(val);
        return;
    }
    int mid = l + r >> 1;
    update(2 * idx, l, mid, i, old, val);
    update(2 * idx + 1, mid + 1, r, i, old, val);
    f[idx].erase(f[idx].find(old));
    f[idx].insert(val);
}
int get(int idx, int l, int r, int u, int v, int k){
    // [u [l, r] v]
    if(v < l || r < u) return ING;
    if(u <= l && r <= v){
        auto it = f[idx].lower_bound(k);
        if(it != f[idx].end()) return *it;
        return ING;
    }
    int mid = l + r >> 1;
    int g1 = get(2 * idx, l, mid, u, v, k);
    int g2 = get(2 * idx + 1, mid + 1, r, u, v, k);
    return min(g1, g2);
}
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int type, x, y, k;
        cin >> type >> x >> y;
        if(type == 1) {
            update(1, 1, n, x, a[x], y);
            a[x] = y;
        }
        else {
            cin >> k;
            int ans = get(1, 1, n, x, y, k);
            cout << ((ans == ING) ? -1 : ans) << endl;
        }
    }
}
signed main() {
    faster();
    // file();
    solve();
}
