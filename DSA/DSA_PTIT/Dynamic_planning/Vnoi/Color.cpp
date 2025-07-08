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

// Bạn An có n chiếc ghế màu trắng, n chiếc ghế màu đen và n chiếc ghế màu đỏ. 
// An muốn chọn ra n chiếc ghế để xếp thành một hàng ngang. 
// Do An không thích màu đỏ nên An không muốn xếp hai chiếc ghế đỏ cạnh nhau. 
// Tính số cách xếp ghế thỏa mãn điều kiện đó.
// Điều kiện: 1 <= n <= 10^5

// Phân tích bài toán:
/*
    Đặt các màu tương ứng là A, B, C.<Trắng, Đen, Đỏ>
    TH1: chỉ có A or B => có dạng f[i] = 2 * f[i - 1]
    TH2: có C:   C, (A or B) => f[i] = 2 * f[i - 2]
    => Tổng là : f[i] = 2 * f[i - 1] + 2 * f[i - 2]

    ta xét bài toán con nhỏ nhất:
    n == 1 => f[n] = 3 A, B, C
    n == 2 => f[n] = 8 AA, AB, BA, BB, AC, BC, CA, CB
*/
void solve(){
    int n;
    cin >> n;
    vector<int> f(n, 0);
    f[1] = 3;
    f[2] = 8;
    for(int i = 3; i <= n; ++i) f[i] = 2 * f[i - 1] + 2 * f[i - 2];
    cout << f[n];
}
signed main() {
    faster();
    file();
    solve();
}