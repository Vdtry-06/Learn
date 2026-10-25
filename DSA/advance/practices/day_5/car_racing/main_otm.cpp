#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll INF = LLONG_MAX / 4;
const int MAX = 105;

int t[MAX], f[MAX];
int n, st;
ll mi;
ll best[MAX][MAX];

void backtrack(int pre, int dur, ll s) {
    // Cat nhanh
    if (s >= mi) return;

    // Hoan thanh
    if (pre == n) {
        mi = s;
        return;
    }

    // Cat trang thai da co thoi gian tot hon
    if (best[pre][dur] <= s) return;
    best[pre][dur] = s;

    int next = pre + 1;

    // Chon 
    backtrack(next, f[next], s + t[next]);

    // Khong chon
    if (dur > 1) {
        backtrack(next, dur - 1, s);
    }
}

void solve() {
    cin >> n >> st;
    f[0] = st;
    t[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> f[i] >> t[i];
    }

    mi = INF;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            best[i][j] = INF;
        }
    }

    backtrack(0, st, 0);

    if (mi == INF) cout << -1;
    else cout << mi;
    cout << endl;
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