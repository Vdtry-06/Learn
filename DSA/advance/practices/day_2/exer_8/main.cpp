#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 1005;
bool adj[MAX][MAX];
stack<int> st;
int used[MAX];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    int d = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) adj[i][j] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        if (adj[u][v] == 1) cout << 1;
        else cout << 0;
        if (i != q - 1) cout << " ";
    }

    cout << endl;
}

int main() {
    // file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << ": ";
        solve();
    }
}