#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e9;
const int MAX = 105;

vector<vector<int>> res;
vector<int> adj[MAX]; 
stack<int> st;
bool used[MAX];
vector<int> ans;
int leaf[MAX];
int neb[MAX];
int point[MAX];
int n, m, k;

void reset() {
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
    }

    while (!st.empty()) st.pop();
    ans.clear();
    res.clear();

    memset(used, false, sizeof(used));
    memset(leaf, 0, sizeof(leaf));
    memset(neb, 0, sizeof(neb));
    memset(point, 0, sizeof(point));

    n = m = k = 0;
}

void DFS(int u) {
    memset(used, false, sizeof(used));
    memset(neb, 0, sizeof(neb));
    ans.clear();
    while (!st.empty()) st.pop();

    used[u] = true;
    st.push(u);
    ans.push_back(u);

    while (!st.empty()) {
        int v = st.top();

        // dk hoan thanh
        if (v == 1) {
            res.push_back(ans);
            used[v] = false; // tra dinh 1 de di dg khac
            st.pop();
            ans.pop_back();
            continue;
        }

        // thu moi diem ke vs v
        if (neb[v] < adj[v].size()) {
            int x = adj[v][neb[v]++];

            if (!used[x]) {
                used[x] = true;
                st.push(x);
                ans.push_back(x);

            }
        } 
        
        // het diem ke, quay lui
        else {
            neb[v] = 0;
            used[v] = false;
            st.pop();
            ans.pop_back();
        }
    }
}

void solve () {
    cin >> n >> m >> k;

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

    int d = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1 && point[i] == 1) {
            leaf[d++] = i;
        }
    }

    for (int i = 0; i < d; i++) DFS(leaf[i]);

    int mx = -1; // số điểm đặc biệt nhiều nhất
    int mi = INF; // số cạnh ít nhất

    for (vector<int> v : res) {
        int d = 0;
        for (int x : v) {
            if (point[x] == 1) d++; 
            // cout << x << " ";
        }

        if (mx < d || (mx == d && mi > v.size() - 1)) {
            mx = d;
            mi = v.size() - 1;
        }
        // cout << endl;
    }
    cout << mx << " " << mi;
    cout << endl;

    res.clear();
}

int main() {
    // file();
    faster();
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        reset();
        cout << "#" << i << " ";
        solve();
    }
}