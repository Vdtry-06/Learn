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
const int MAX = 1e6 + 5;
int f[1005];
int n;
ll BackTracking(ll n){
    if(n == 1) return 0;
    if(f[n] != -1) return f[n];
    ll mi = n;
    if(n % 2 == 0) mi = min(mi, BackTracking(n / 2) + 1);
    if(n % 3 == 0) mi = min(mi, BackTracking(n / 3) + 1);
    mi = min(mi, BackTracking(n - 1) + 1);
    f[n] = mi;
    return mi;
}
void solve(){
    memset(f, -1, sizeof(f));
    cin >> n;
    cout << BackTracking(n);
}
int main(){
    file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    } 
}