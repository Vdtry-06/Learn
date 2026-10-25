#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int INF = 1e9;
const int MAX = 105;
int t[MAX], f[MAX];
int n, st;
int used[MAX];
ll mi;

void backtrack(int pre, int dur, ll s) {
    // cat nhanh
    if (s >= mi) return;

    // hoan thanh
    if (pre == n - 1) {
        mi = min(mi, s);
        return;
    }

    // thu lua chon
    int lst = min(n - 1, pre + dur);

    for (int i = pre + 1; i <= lst; i++) {
        // chon
        backtrack(i, f[i], s + t[i]);

        // ko chon
        if (dur > i - pre) {
            backtrack(i, dur - (i - pre), s);
        }
    }


}

void solve() {
    cin >> n >> st;
    mi = INF;
    for (int i = 0; i < n; i++) {
        cin >> f[i] >> t[i];
    }

    backtrack(-1, st, 0);

    cout << mi << endl;
}

int main() {
    file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}