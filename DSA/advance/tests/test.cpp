#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
queue<int> q;

void solve() {
    int n;
    cin >> n;
    vector<string> ans;
    while(n > 0) {
        string s; cin >> s;
        if (s == "ENQUEUE") {
            int x; cin >> x;
            q.push(x);
        } else if (s == "DEQUEUE") {
            if (!q.empty()) q.pop();
        } else {
            if (!q.empty()) {
                ans.push_back(to_string(q.front()));
            } else {
                ans.push_back("EMPTY");
            }
        }
        n--;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
    while(!q.empty()) q.pop();
    for (int i = 0; i < ans.size(); i++) ans[i].clear();
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