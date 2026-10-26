#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e9;
const int MAX = 105;

vector<int> adj[MAX];
bool used[MAX];
int leaf[MAX];
int point[MAX];
int n, m, k;
int mx, mi;

void DFS(int u, int cnt, int len) {

    if (u == 1) {
        if (mx < cnt || (cnt == mx && len < mi)) {
            mx = cnt;
            mi = len;
        }
        return;
    }

    if (mx == k && len >= mi) return;

    for (int x : adj[u]) {
        if (used[x]) continue;

        used[x] = true; 
        DFS(x, cnt + point[x], len + 1);
        used[x] = false;
    }
}

void solve() {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        point[i] = 0;
        used[i] = false;
    }

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        point[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    mx = -1;
    mi = INF;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1 && point[i] == 1) {
            used[i] = true;
            DFS(i, 1, 0);       // lá là điểm đặc biệt nên cnt bắt đầu = 1
            used[i] = false;
        }
    }

    cout << mx << " " << mi << endl;
}

int main() {
    // file();
    faster();
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}