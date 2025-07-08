#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int a[100]; // mảng a để lưu các giá trị thỏa mãn của từng cấu hình
int n; // số lượng ptu của xâu nhị phân
int d = 0; // số cấu hình thỏa mãn của xâu nhị phân
bool check; // kiểm tra cấu hình cuối cùng
vector<string> v; // cấu hình thỏa mãn được in ra
string s; // lưu các giá trị thỏa mãn của từng cấu hình

/* Hàm khởi tạo */
void ktao()
{
    FOR(i, 1, n) a[i] = 0;
}

/* hàm sinh kế tiếp */
void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if(i == 0) check = 0;
    else a[i] = 1;
}

/* hàm in ra kết quả */
void solve()
{
    check = 1;
    while(check)
    {
        d++;
        FOR(i, 1, n)
        {
            s += to_string(a[i]);
        }
        v.push_back(s);
        s.clear();
        sinh();
    }
    cout << "so luong cau hinh xau nhi phan co do dai " << n << " la: ";
    cout << d << endl;
    For(i, 0, v.size()) cout << v[i] << endl;
}

/* hàm chính */
signed main()
{
    cout << "nhap do dai xau nhi phan: ";
    file();
    faster();
    cin >> n;
    ktao();
    solve();
}
