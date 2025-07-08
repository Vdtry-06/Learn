#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 100000;

// Tổng số nguyên tố lớn nhất từ l -> r
vector<int> res(MAX + 1, 0);

void prime() {
    for(int i = 2; i <= MAX; ++i) {
        if(res[i] == 0) {
            for(int j = i; j <= MAX; j += i) {
                res[j] = i;
            }
        }
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    ll s = 0;
    for(int i = l; i <= r; ++i) {
        s += res[i];
    }
    cout << s << endl;
}

int main() {
    faster();
    // file();
    prime();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
