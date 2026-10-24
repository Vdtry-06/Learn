#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e18;
const int MAX = 105;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char dz[] ={'D', 'L', 'U', 'R'};
bool used[MAX][MAX];
int a[MAX][MAX];
int n;
vector<string> res;

void backtrack(int i, int j, string s) {
    used[i][j] = true;

    // 1. ktra hoan thanh
    if (i == n - 1 && j == n - 1) {
        res.push_back(s);
        used[i][j] = false;
        return;
    }

    // thu tung doan chon
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        char z = dz[k];

        if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 0) continue;
        
        if (used[x][y]) continue;

        backtrack(x, y, s + dz[k]);
    }

    used[i][j] = false;
}

void solve () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    memset(used, false, sizeof(used));

    string s;

    backtrack(0, 0, s);

    sort(res.begin(), res.end());

    for (string x : res) {
        cout << x << endl;
    }

    cout << endl;

    res.clear();
}

int main() {
    // file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}
