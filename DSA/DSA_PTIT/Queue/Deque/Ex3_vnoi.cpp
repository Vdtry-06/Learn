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
const int MAX = 3e5 + 5;
int a[MAX];
int L[MAX], R[MAX];
int l[MAX], r[MAX];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    deque<int> dq;

    dq.clear();
    for(int k = 1; k <= n; ++k){
        while(!dq.empty() && a[dq.front()] <= a[k]) dq.pop_front();
        if(!dq.empty()) L[k] = dq.front() + 1;
        else L[k] = k;
        dq.push_front(k);
    }

    dq.clear();
    for(int k = n; k >= 1; --k){
        while(!dq.empty() && a[dq.front()] <= a[k]) dq.pop_front();
        if(!dq.empty()) R[k] = dq.front() - 1;
        else R[k] = k;
        dq.push_front(k);
    }

    dq.clear();
    for(int k = 1; k <= n; ++k){
        while(!dq.empty() && a[dq.front()] >= a[k]) dq.pop_front();
        if(!dq.empty()) l[k] = dq.front() + 1;
        else l[k] = k;
        dq.push_front(k);
    }

    dq.clear();
    for(int k = n; k >= 1; --k){
        while(!dq.empty() && a[dq.front()] >= a[k]) dq.pop_front();
        if(!dq.empty()) r[k] = dq.front() - 1;
        else r[k] = k;
        dq.push_front(k);
    }

    vector<vector<int>> G(n + 1);
    for(int k = 1; k <= n; ++k) G[k].push_back(k + 1);
    for(int k = 1; k <= n; ++k){
        if(L[k] - 1 >= 1 && R[k] + 1 <= n && a[k] < min(a[L[k] - 1], a[R[k] + 1])){
            G[L[k] - 1].push_back(R[k] + 1);
        }
    }
    for(int k = 1; k <= n; ++k){
        if(l[k] - 1 >= 1 && r[k] + 1 <= n && a[k] > max(a[l[k] - 1], a[r[k] + 1])){
            G[l[k] - 1].push_back(r[k] + 1);
        }
    }
    
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (v <= n && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    if(dist[n] == INT_MAX) cout << -1;
    else cout << dist[n];
}
int main(){
    // file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
// 3
// 5
// 1 3 1 4 5
// 4
// 4 2 2 4
// 5
// 100 1 100 1 100