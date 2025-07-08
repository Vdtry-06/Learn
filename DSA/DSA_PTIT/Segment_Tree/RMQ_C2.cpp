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
void Build(int idx, int l, int r, int f[], int a[]){
    if(l == r) f[idx] = a[l];
    else{
        int mid = (l + r) >> 1;
        Build(2 * idx, l, mid, f, a);
        Build(2 * idx + 1, mid + 1, r, f, a);
        f[idx] = min(f[2 * idx], f[2 * idx + 1]);
    }
}
int Query(int idx, int l, int r, int f[], int a[], int i, int j){
    if(l > j || i > r) return ING;
    if(i <= l && r <= j) return f[idx];
    int mid = (l + r) >> 1;
    int p1 = Query(2 * idx, l, mid, f, a, i, j);
    int p2 = Query(2 * idx + 1, mid + 1, r, f, a, i, j);
    return min(p1, p2);
}
void solve(){   
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int f[4 * n];
    Build(1, 1, n, f, a);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << Query(1, 1, n, f, a, l, r) << endl;
    }
}
signed main() {
    faster();
    file();
    solve();
}
/*
10 4
2 4 3 1 6 7 8 9 1 7
1 7
2 3
3 9
5 8

*/