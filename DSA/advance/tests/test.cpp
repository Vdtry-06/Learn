#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
vector<int> adj[MAX];
stack<int> st;
int graph[MAX];

void DFS(int r) {
    st.push(r);
    graph[r] = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (graph[v] == -1) {
                st.push(v);
                graph[v] = graph[u] + 1;
            }
        } 
    }

}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i <= n; i++) graph[i] = -1;
    DFS(1);
    vector<int> ans;
    while (q > 0) {
        int x; cin >> x;
        ans.push_back(graph[x]);
        q--;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
    ans.clear();
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) adj[i].clear();
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