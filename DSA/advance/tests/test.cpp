#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
vector<int> adj[MAX];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int d = 0;
    for (int i = 1; i <= n; i++) { 
        if(adj[i].size() == 0) d++;
    }
    cout << d << endl;
    for (int i = 1; i <= n; i++) adj[i].clear();
}

int main() {
    file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << ": ";
        solve();
    }
}