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
const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 5;
/*
    Cho một dãy nhị phân có N phần tử. Ban đầu cả dãy có giá trị toàn 0. 
    Mỗi bước với hai giá trị x và y (1 ≤ x ≤ y ≤ N), bạn sẽ thay đổi tất cả các bit từ vị trí x đến vị trí y 
    (nếu đang là 1 thì thành 0 và ngược lại).
    Hãy cho biết sau Q lần thực hiện các truy vấn với 2 cặp số x, y 
    thì trạng thái cuối cùng của dãy nhị phân là gì.
    Input
    Dòng đầu ghi hai số N và Q
    Q dòng sau mỗi dòng ghi hai số x và y.

    Output
    Ghi ra dãy kết quả.

    Ví dụ
    Input
    3 2
    1 2
    1 3
    
    Output
    0 0 1
    Ràng buộc:
    50% test tương ứng với 1 ≤ N, Q ≤ 1000
    50% test tương ứng với  1 ≤ N, Q ≤ 100000
*/
vector<int> f(4 * MAX, 0);
vector<int> lazy(4 * MAX, 0);
void fix(int id, int l, int r){
    if(!lazy[id]) return;
    f[id] = (r - l + 1) - f[id];
    if(l != r){
        lazy[2 * id] ^= 1;
        lazy[2 * id + 1] ^= 1;
    }
    lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v){
    fix(id, l, r);
    if(r < u || l > v) return;
    if(u <= l && r <= v){
        lazy[id] ^= 1;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v);
    update(2 * id + 1, mid + 1, r, u, v);
    f[id] = f[2 * id] + f[2 * id + 1];
}
int get(int id, int l, int r, int i){
    fix(id, l, r);
    if(l == r) return f[id];
    int mid = l + r >> 1;
    if(i <= mid) return get(2 * id, l, mid, i);
    else return get(2 * id + 1, mid + 1, r, i);
}
void solve(){
    int n, q;
    cin >> n >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        update(1, 1, n, l, r);
    }
    for(int i = 1; i <= n; ++i){
        cout << get(1, 1, n, i) << " ";
    }
}
signed main() {
    faster();
    // file();
    solve();
}
