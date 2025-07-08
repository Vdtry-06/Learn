#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define pq_max priority_queue<int>
#define pr pair<ll, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF = 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

// Cho dãy số nguyên dương a1,a2,...an. Tìm độ dài của dãy con không giảm dài nhất của dãy.
// Dãy con của một dãy là dãy số thu được bằng cách bỏ đi một số phần tử của dãy ban đầu.
// Điều kiện: 1 <= n <= 1000 và 1 <= a1,a2,...,an <= 10^9.

/*
    Phân tích bài toán:
        ví dụ:  7
        a[i]    1 2 4 3 7 5 6
        f[i]    1 2 3 3 4 4 5
        => f[i] = f[j] + 1 với điều kiện a[i] >= a[j]
        => f[i] = max(f[i], f[j] + 1)
        phân tích bài toán con:
            i = 1 -> n  => f[i] = 1 vì 1 số cũng thỏa mãn là 1 dãy
*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> idx(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        idx[i] = i;
    }
    vector<int> f(n + 1, 0);
    vector<int> d(n, -1);
    int mx = 0, end_idx;
    // Dynamic programing
    for(int i = 1; i <= n; ++i){
        f[i] = 1;
        for(int j = 1; j < i; ++j){
            if(a[i] >= a[j] && f[i] < f[j] + 1) {
                f[i] = f[j] + 1;
                d[i] = j;
            }
        }
        if(mx < f[i]){
            mx = f[i];
            end_idx = i;
        }
    }
    cout << mx << endl;
    // Traceback
    vector<int> res;
    for(int i = end_idx; i != -1; i = d[i]){
        res.push_back(idx[i]);
    }
    for(int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
}
signed main() {
    faster();
    file();
    solve();
}