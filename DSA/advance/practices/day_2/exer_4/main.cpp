#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
stack<int> st;
string x = "([{";
string y = ")]}";

void solve() {
    string s; cin >> s;
    bool check = true;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < x.length(); j++) {
            if (s[i] == x[j]) st.push(j);
        }
        for (int j = 0; j < y.length(); j++) {
            if (s[i] != y[j]) continue;
            if (st.empty() || st.top() != j) {
                check = false;
                break;
            }
            st.pop();
        }
    }
    if (!st.empty()) check = false;
    if (check == true) cout << "YES";
    else cout << "NO";
    cout << endl;
    while(!st.empty()) st.pop();
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