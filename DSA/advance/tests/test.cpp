#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e18;
const int MAX = 105;
bool used[MAX][MAX];
int a[MAX][MAX];

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

bool backtrack(int i, int j, int st) {
    // trang thai buoc
    a[i][j] = st;
    used[i][j] = true;
    
    // dk hoan thanh
    if (st == n * n - 1) {
        return true;
    }

    // thu 8 lan di
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        
        // lua chon ko hop le
        if (x < 0 || x >= n || y < 0 || y >= n || used[x][y] == true) continue;

        // neu tim dc kq 
        if (backtrack(x, y, st + 1)) return true;
    }

    // bo chon
    used[i][j] = false;
    a[i][j] = -1;
    return false;
}

void solve () {
    cin >> n;
    memset(used, false, sizeof(used));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = -1;
    if (backtrack(0, 0, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << a[i][j] << " ";
            cout << endl;
        }
    }
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
