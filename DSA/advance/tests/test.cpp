#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e18;
const int MAX = 1005;

void backtrack(int idx, string &s, vector<string> &res) {

    // 1. kiem tra hoan thanh
    if (idx == s.length()) {
        res.push_back(s);
        return;
    }

    // 3. thu tung doan
    for (int i = idx; i < s.length(); i++) {

        // 4. Chon
        swap(s[idx], s[i]);

        // trang thai moi
        backtrack(idx + 1, s, res);

        // 5. Bo chon
        swap(s[idx], s[i]);
    }
}


void solve () {
    string s;
    cin >> s;

    vector<string> res;
    backtrack(0, s, res);
    sort(res.begin(), res.end());

    for (string x : res) cout << x << " ";
    cout << endl;
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
