#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll L[4 * MAX], R[4 * MAX];
ll del[4 * MAX], ass[4 * MAX], a[4 * MAX];

ll len(int i){
    return R[i] - L[i] + 1;
}
void Add(int i, int val){
    del[i] += val;
    a[i] += len(i) * val;
}
void Prototype(int i, int val){
    ass[i] = val;
    del[i] = 0;
    a[i] = len(i) * val;
}
void Push(int i){
    if(ass[i]){
        Prototype(2 * i, ass[i]);
        Prototype(2 * i + 1, ass[i]);
        ass[i] = 0;
    }
    if(del[i]){
        Add(2 * i, del[i]);
        Add(2 * i + 1, del[i]);
        del[i] = 0;
    }
}
void Build(int i, int l, int r){
    L[i] = l; R[i] = r;
    if(l == r){
        a[i] = a[l];
        return;
    }
    int mid = l + r >> 1;
    Build(2 * i, l, mid);
    Build(2 * i + 1, mid + 1, r);
    a[i] = a[2 * i] + a[2 * i + 1];
}
void Add(int i, int l, int r, int val){
    if(l > R[i] || r < L[i]) return;
    if(l <= L[i] && R[i] <= r){
        Add(i, val);
        return;
    }
    Push(i);
    Add(2 * i, l, r, val);
    Add(2 * i + 1, l, r, val);
    a[i] = a[2 * i] + a[2 * i + 1];
}
void Prototype(int i, int l, int r, int val){
    if(l > R[i] || r < L[i]) return;
    if(l <= L[i] && R[i] <= r){
        Prototype(i, val);
        return;
    }
    Push(i);
    Prototype(2 * i, l, r, val);
    Prototype(2 * i + 1, l, r, val);
    a[i] = a[2 * i] + a[2 * i + 1];
}
ll Query(int i, int l, int r){
    if(l > R[i] || r < L[i]) return 0;
    if(l <= L[i] && R[i] <= r){
        return a[i];
    }
    Push(i);
    ll s1 = Query(2 * i, l, r);
    ll s2 = Query(2 * i + 1, l, r);
    a[i] = a[2 * i] + a[2 * i + 1];
    return s1 + s2;
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    Build(1, 1, n);
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            int val;
            cin >> val;
            Add(1, l, r, val);
        }
        else if(t == 2){
            int val;
            cin >> val;
            Prototype(1, l, r, val);
        }
        else{
            cout << Query(1, l, r) << endl;
        }
    }
}
signed main() {
    faster();
    file();
    solve();
}
