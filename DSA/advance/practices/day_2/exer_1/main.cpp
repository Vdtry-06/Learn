#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 1005;
int a[MAX];

void add_x(int x, int a[], int n) {
    a[n] = x;
}

void first_add(int x, int a[], int n) {
    for (int i = n; i >= 1; i--) a[i] = a[i - 1];
    a[0] = x;
}

void remove_x(int x, int a[], int n) {
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            idx = i;
            break;
        }
    }
    for (int i = idx; i < n; i++) a[i] = a[i + 1];
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        int x; cin >> x;
        if (s == "ADD") {
            add_x(x, a, n);
            n++;
        } else if (s == "FIRST") {
            n++;
            first_add(x, a, n);
        } else {
            remove_x(x, a, n);
            n--;
        }
    }
    if (n == 0) cout << "EMPTY";
    else for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
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