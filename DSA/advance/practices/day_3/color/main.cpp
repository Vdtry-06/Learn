#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 1005;
int a[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;

int d = 0;

bool check(int i, int j) {
    for (int mask = 0; mask < 16; mask++) {
        ll sum = 0;
        int tmp = mask;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            
            if (tmp % 2 == 1) sum += a[x][y];
            else sum -= a[x][y];
            tmp /= 2;
        }
        if (sum == a[i][j]) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    d = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(i, j)) d++;
        }
    }

    cout << d << endl;
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
