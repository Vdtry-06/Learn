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

// Cho N đồng xu và giá tiền của mỗi đồng (V0, V1,...,Vn - 1), và số S. 
// Tìm số đồng xu nhỏ nhất để tổng giá trị của chúng bằng S
// (số lượng đồng xu không giới hạn).

/*
    Phân tích bài toán:
        Ta gọi mảng f[s] là số đồng xu ít nhất để tổng bằng s.
        TH1: nếu không có phương án nào: f[s] = -1
        TH2: 
            xét bài toán con: với s = 0 => f[0] = 0;
            nhận xét rằng: s có thể giảm dần về 0 khi trừ cho giá trị mảng v
                ta biểu diễn s - vj, với s được giảm mỗi lần là s = s - vj
                => công thức tổng quát f[s - v[j]] + 1: => f[i] = f[i - v[j]] + 1
                    f[i] = min(f[i], f[i - v[j]] + 1) 
*/
void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int &x: v) cin >> x;
    vector<int> f(s + 1, ING);
    f[0] = 0;
    for(int i = 1; i <= s; ++i){
        for(int j = 0; j < n; ++j){
            if(i >= v[j]) f[i] = min(f[i], f[i - v[j]] + 1);
        }
    }
    if(f[s] == ING){
        cout << -1;
        return;
    }
    cout << f[s];
}
signed main() {
    faster();
    file();
    solve();
}
/*
3 11
1 3 5
3
5 3 3
*/
