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
int d; // số cấu hình thỏa mãn của xâu nhị phân
bool check; // kiểm tra cấu hình cuối cùng
vector<string> v; // cấu hình thỏa mãn được in ra
string s; // lưu các giá trị thỏa mãn của từng cấu hình
int k; // số bit 1 duy nhất liên tiếp

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

/*hàm kiểm tra bit 1 liên tiếp duy nhất */
bool ck_1()
{
    int cnt = 0; // số lượng bit 1 liên tiếp duy nhất
    int f[n]; // mảng tăng các gtri bit 1 liên tiếp
    memset(f, 0, sizeof(f));
    FOR(i, 1, n)
    {
        if(a[i] == 1)
        {
            if(i == 1) f[i] = 1;
            f[i] = f[i - 1] + 1;
        }
        else f[i] = 0; 
        if(f[i] == k) cnt++;
        else if(f[i] > k) return 0;
    }
    return cnt == 1;
}

/*hàm in kết quả */
void solve()
{
    check = 1;
    while(check)
    {
        if(ck_1())
        {
            d++;
            FOR(i, 1, n)
            {
                s += to_string(a[i]);
            }
            v.push_back(s);
            s.clear();
        } 
        sinh();
    }
    cout << "so luong cau hinh thoa man: ";
    cout << d << endl;
    For(i, 0, v.size()) cout << v[i] << endl;
}

/*hàm chính */
signed main()
{   
    // file();
    // faster();
    cout << "nhap xau nhi phan co do dai: ";
    cin >> n;
    cout << "nhap so luong bit 1 lien tiep duy nhat: ";
    cin >> k;
    ktao();
    solve();
}
