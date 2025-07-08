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
int a[100005];
int n, s, mi;
void BackTracking(int i, int sum, int cnt){
    if(sum > s || cnt > mi) return;
    if(i == n){
        if(sum == s) mi = min(mi, cnt);
        return;
    } 
    BackTracking(i + 1, sum, cnt);
    BackTracking(i + 1, sum + a[i], cnt + 1);
}
void solve(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    mi = ING;
    BackTracking(0, 0, 0);
    if(mi == ING) cout << -1;
    else cout << mi;
}
int main(){
    file();
    faster();
    solve();
}