#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 105;
int a[MAX][MAX];
int dis[MAX];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> dis[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    } 

    for (int d = 0; d < k; d++) {
        if (dis[d] == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = m - 2; j >= 0; j--) {
                    if (a[i][j + 1] != 0) {
                        a[i][j] = a[i][j] + a[i][j + 1];
                        a[i][j + 1] = 0;
                        break; 
                    }
                }
            }
        } else if (dis[d] == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (a[i][j - 1] != 0) {
                        a[i][j] = a[i][j] + a[i][j - 1];
                        a[i][j - 1] = 0;
                        break; 
                    }
                }
            }
        } else if (dis[d] == 3) {
            for (int j = 0; j < m; j++) {
                for (int i = n - 2; i >= 0; i--) {
                    if (a[i + 1][j] != 0) {
                        a[i][j] = a[i][j] + a[i + 1][j];
                        a[i + 1][j] = 0;
                        break;
                    }
                }
            }
        } else {
            for (int j = 0; j < m; j++) {
                for (int i = 1; i < n; i++) {
                    if (a[i - 1][j] != 0) {
                        a[i][j] = a[i][j] + a[i - 1][j];
                        a[i - 1][j] = 0;
                        break; 
                    }
                }
            }
        }
    }

    int mx = 0, vtx = 0, vty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mx < a[i][j]) {
                mx = a[i][j];
                vtx = i;
                vty = j;
            }
        }
    }
    
    cout << mx << " " << vtx + 1 << " " << vty + 1 << endl;
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
