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
    Có n cuộc họp, cuộc họp thứ i bắt đầu vào thời điểm Ai và kết thúc ở thời điểm Bi. 
    Do chỉ có một phòng hội thảo nên 2 cuộc họp bất kì sẽ được cùng bố trí phục vụ 
    nếu khoảng thời gian làm việc của chúng chỉ giao nhau tại đầu mút hoặc không giao nhau. 
    Hãy bố trí phòng họp để phục vụ được nhiều cuộc họp nhất.
    Điều kiện: 1 <= n <= 1000 và 1 <= ai <= bi <= 10^9 với mọi i = 1,2,...,n.
*/
/*
    Phân tích bài toán:
        4
        1 3
        4 6
        2 5
        7 8

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
            f[i] = max(f[i], f[j] + 1) với đk Ai >= Bj
        bài toán con: f[i] = 1;
*/
struct Meeting{
    int a; // thời điểm bắt đầu cuộc họp
    int b; // thời điểm kết thúc cuộc họp
    int idx; // số thứ tự cuộc họp
};
bool cmp(Meeting A, Meeting B){
    if(A.a == B.a){
        return A.b < B.b;
    }
    return A.a < B.a;
}
void solve(){
    int n;
    cin >> n;
    vector<Meeting> A(n);
    for(int i = 0; i < n; ++i){
        A[i].idx = i;
        cin >> A[i].a >> A[i].b;
    }
    sort(A.begin(), A.end(), cmp);
    vector<int> f(n, 0);
    vector<int> d(n, -1);
    int mx = 0, end_idx = 0;
    // Quy hoạch động
    for(int i = 0; i < n; ++i){
        f[i] = 1;
        for(int j = 0; j < i; ++j){
            if(A[i].a >= A[j].b && f[i] < f[j] + 1) {
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
    // Truy vết
    vector<int> res;
    for(int i = end_idx; i != -1; i = d[i]){
        res.push_back(A[i].idx);
    }
    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i] << " ";
    }
}
signed main() {
    faster();
    file();
    solve();
}