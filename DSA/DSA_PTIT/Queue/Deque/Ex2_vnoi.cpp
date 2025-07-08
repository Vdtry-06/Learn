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
int a[MAX];
int f[MAX];
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n + 1; ++i) f[i] = ING;
    f[0] = 0;
    deque<int> dq;
    dq.push_back(0);
    int s = 0;
    for(int i = 1; i <= n + 1; ++i){
        s += a[i];
        while(!dq.empty() && dq.front() < i - k) dq.pop_front();
        f[i] = f[dq.front()] + a[i];
        while(!dq.empty() && f[dq.back()] >= f[i]) dq.pop_back(); 
        dq.push_back(i);
    }
    cout << s - f[n + 1];
}
signed main() {
    faster();
    file();
    solve();
}
// 7 3
// 1 4 2 3 6 5 9
