#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
int a[10005];
int f[10005];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (f[a[i]] != 0) {
            ans.push_back(a[i]);
            f[a[i]] = 0;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << a[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << ": ";
        solve();
    }
}