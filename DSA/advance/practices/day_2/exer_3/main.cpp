#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
stack<int> st;

void solve() {
    int q; cin >> q;
    vector<string> ans;
    while (q > 0) {
        string s; cin >> s;
        if (s == "PUSH") {
            int x; cin >> x;
            st.push(x);
        } else if (s == "TOP") {
            if (!st.empty()) ans.push_back(to_string(st.top()));
            else ans.push_back("EMPTY");
        } else {
            if (!st.empty()) st.pop();
        }
        q--;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++) ans[i].clear();
    while (!st.empty()) st.pop();
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