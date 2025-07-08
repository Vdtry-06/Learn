#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mx = *max_element(a.begin(), a.end()), vt = 0, mx1 = 0, mx2 = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == mx){
            vt = i;
        }
    }
    int d = 0;
    for(int i = 0; i < vt; ++i){
        mx1 = max(mx, a[i]);
        d += mx1 - a[i];
    }
    for(int i = n; i >= vt; --i){
        mx2 = max(mx2, a[i]);
        d += mx2 - a[i];
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
6
4 2 0 3 2 5