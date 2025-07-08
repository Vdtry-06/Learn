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
int n, v;
struct Knapsack{
    ll w;
    ll c;
};
Knapsack a[1005];
bool cmp(Knapsack a, Knapsack b){
    return (double) a.c / a.w > (double) b.c / b.w;
}
ll Try(int i, ll w, ll c){
    if(w > v) return 0;
    if(i == n && w <= v){
        return c;
    }
    ll lay = Try(i + 1, w + a[i].w, c + a[i].c);
    ll ko_lay = Try(i + 1, w, c);
    return max(lay, ko_lay);

}
void solve(){
    cin >> n >> v;
    FOR(i, 1, n) cin >> a[i].w;
    FOR(i, 1, n) cin >> a[i].c;
    sort(a + 1, a + n + 1, cmp);
    cout << Try(1, 0, 0);
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