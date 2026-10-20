#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 10005;
queue<int> q;

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size() >= 2) {
        cout << q.front() << " "; q.pop();
        q.push(q.front()); q.pop();
    } 

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
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