#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 105;
int a[MAX][MAX];
int s[MAX][MAX];
int s2[MAX][MAX];
int n, m;


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    
    int div = n / m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < div; j++) {
            s[i][j] = 0;
            s2[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int pos = j % div;
            if ((j / div) % 2 == 0) s[i][pos] += a[i][j];
            else s2[i][pos] += a[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < div; j++) {
            mx = max(mx, s[i][j] + s2[i][div - j - 1]);
        }
    }
    cout << mx << endl;
    
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
