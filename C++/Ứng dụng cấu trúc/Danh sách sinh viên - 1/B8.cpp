#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define pq_max priority_queue<int>
#define FORD(i, r, l) for (int i = r; i >= l; i--)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define For(i, l, r) for (int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr>
#define fi first
#define se second
#define sze size()
#define endl '\n'
const ll LINF = 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

struct SinhVien 
{
    string msv, t, l, ns;
    double gpa;
};
void nhap(SinhVien ds[], int n)
{
    // cin.ignore();
    For(i, 0, n)
    {
        cin.ignore();
        getline(cin, ds[i].t);
        getline(cin, ds[i].l);
        getline(cin, ds[i].ns);
        cin >> ds[i].gpa;
    }
}
void in(SinhVien ds[], int n)
{
    string s = "";
    For(i, 0, n)
    {
        if(i < 9) s = "00";
        else s = "0";
        ds[i].msv = "B20DCCN";
        ds[i].msv += s;
        ds[i].msv += to_string(i + 1);
        string tmp, z = "";
        stringstream ss(ds[i].ns);
        while(getline(ss, tmp, '/'))
        {
            if(tmp.size() < 2) z += "0";
            z += tmp;
            if(tmp.size() < 4) z += "/";
        }
        cout << ds[i].msv << " " << ds[i].t << " " << ds[i].l << " "<< z << " " << fixed << setprecision(2) << ds[i].gpa << endl;
    }
}
int main(){
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}