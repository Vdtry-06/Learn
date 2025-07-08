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
/*
    Trung tâm tính toán hiệu năng cao nhận được đơn đặt hàng của n khách hàng. 
    Khách hàng i muốn sử dụng máy trong khoảng thời gian từ Ai đến Bi và trả tiền thuê là Ci. 
    Hãy bố trí lịch thuê máy để tổng số tiền thu được là lớn nhất 
    mà thời gian sử dụng máy của 2 khách hàng bất kì được phục vụ đều không giao nhau 
    (cả trung tâm chỉ có một máy cho thuê).
    Điều kiện: 1 <= n <= 1000 và 1 <= Ai <= Bi <= 10^9, 1 <= Ci <= 10^6 với mọi i = 1,2,...,n.
*/

/*
    Phân tích bài toán:
        4
        1 3 3
        4 6 2
        2 5 1
        7 8 5
        => 10 : 0, 1, 3

        ---A1-----------A3------B1----A2-----B3-----B2-----A4-----------B4----------------->
            -------------------->
                                       ------------->
                        --------------------->
                                                            ------------>
        
        Sắp xếp lại theo Ai, bi

        ---A1-----------A2------B1----A3-----B2-----B3-----A4-----------B4----------------->
            -------------------->
                        --------------------->
                                       ------------->
                                                            ------------>
    f[i]             1            1          2                    3 
        
        Từ đường thẳng trên ta rút ra được công thức:
            f[i] = max(f[i], f[j] + C[i]) với đk Ai >= Bj
        bài toán con: f[i] = 1;
*/
struct Machine{
    int a, b, c;
    int idx;
};
bool cmp(Machine A, Machine B){
    return A.a < B.a || (A.a == B.a && A.b < B.b);
}
void solve(){
    int n;
    cin >> n;
    vector<Machine> A(n);
    for(int i = 0; i < n; ++i){
        cin >> A[i].a >> A[i].b >> A[i].c;
        A[i].idx = i;
    }
    sort(A.begin(), A.end(), cmp);
    int mx = 0, end_idx = 0;
    vector<int> f(n + 1, 0), d(n, -1);
    // Dynamic programing
    for(int i = 0; i < n; ++i){
        f[i] = A[i].c;
        for(int j = 0; j < i; ++j){
            if(A[i].a >= A[j].b && f[i] < f[j] + A[i].c){
                f[i] = f[j] + A[i].c;
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
        res.push_back(A[i].idx);
    }
    for(int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
}
signed main() {
    faster();
    file();
    solve();
}