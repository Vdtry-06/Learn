#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a;
int n, k;

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<int> idx(n + 1);
    for (int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }

    int i = 0;
    while (k > 0 && i < n) {
        if (a[i] != n - i) {
            int current_idx = idx[n - i];
            swap(a[i], a[current_idx]);
            idx[a[current_idx]] = current_idx;
            idx[n - i] = i;
            k--;
        }
        i++;
    }

    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();

    return 0;
}
