#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;
struct node{
    int s, mx;
};

// ham ket hop
node Merge(node left, node right){
    node par;
    par.s = left.s + right.s;
    par.mx = left.mx + right.mx;
    return par; 
}

// xay dung cay phan doan
void Build(vector<int> &a, vector<node> &T, int l, int r, int pos){
    if(l == r){
        T[pos].s = a[l];
        T[pos].mx = max(0, a[l]);
        return;
    }
    int mid = (l + r) / 2;
    Build(a, T, l, mid, 2 * pos + 1);
    Build(a, T, mid + 1, r, 2 * pos + 2);
    T[pos] = Merge(T[2 * pos + 1], T[2 * pos + 2]);
}

// Truy van cay phan doan
node Query(vector<node> &T, int l, int r, int L, int R, int pos){
    if(l <= L && r >= R) return T[pos];
    if(l > R || r < L) return {0, 0};
    int mid = (L + R) / 2;
    node left = Query(T, l, r, L, mid, 2 * pos + 1);
    node right = Query(T, l, r, mid + 1, R, 2 * pos + 2);
    return Merge(left, right);
}
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<node> T(4 * n);
    Build(a, T, 0, n - 1, 0);
    while(q--){
        int l, r;
        cin >> l >> r;
        node res = Query(T, l - 1, r - 1, 0, n - 1, 0);
        cout << res.mx << endl;
    }
}
int main(){
    file();
    faster();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    //     cout << endl;
    // }
}
// 5 4
// -1 2 -3 4 1
// 2 5
// 3 3
// 5 4
// 2 3