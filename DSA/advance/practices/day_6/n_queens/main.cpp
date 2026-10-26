#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e9;
const int MAX = 105;
bool col[MAX];
bool dia1[2 * MAX];
bool dia2[2 * MAX];
int n;
ll res;

// da duyet
bool check(int i, int j) {
    return !col[j] && !dia1[i + j] && !dia2[i - j + n - 1];
}

void backtrack(int i, int j, int d) {
    // cap nhat trang thai
    col[j] = dia1[i + j] = dia2[i - j + n - 1] = true;
    d++;
    
    // hoan thanh
    if (d == n) {
        res += 1;
        col[j] = dia1[i + j] = dia2[i - j + n - 1] = false;
        d--;
        return;
    }

    // thu lua chon
    int row = i + 1;
    for (int col = 0; col < n; col++) {
        // loai dk ko tm
        if (!check(row, col)) continue;

        backtrack(row, col, d);
    }

    col[j] = dia1[i + j] = dia2[i - j + n - 1] = false;
    d--;
}


void solve () {
    cin >> n;

    memset(col, false, sizeof(col));
    memset(dia1, false, sizeof(dia1));
    memset(dia2, false, sizeof(dia2));
    
    res = 0;

    for (int j = 0; j < n; j++) {
        backtrack(0, j, 0);
    }

    cout << res << endl;
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