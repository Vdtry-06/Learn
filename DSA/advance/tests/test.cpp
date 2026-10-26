#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e9;
const int MAX = 105;
int a[MAX][MAX];
bool picked[MAX];
int n, m;
int res = 0;

void backtrack(int i, int s) {
    // 1. hoan thanh
    if (i >= n) {
        res = max(res, s);
        return;
    }

    // 2. thu chon
    for (int j = 0; j < m; j++) {
        // 2.1. loai dk ko tm
        if (picked[j]) continue;

        // 2.2. danh dau da chon
        picked[j] = true;
        // cout << a[i][j] << " ";

        // 2.3. chon
        backtrack(i + 1, s + a[i][j]);

        // 2.4. bo chon
        picked[j] = false;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    memset(picked, false, sizeof(picked));
    res = 0;
   
    backtrack(0, 0);

    cout << res << endl;

}

int main() {
    file();
    faster();
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}