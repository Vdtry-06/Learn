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
const int MAX = 1e6 + 5;
string Add(string a, string b){
    string res = "";
    int du = 0;
    int mid = 0;
    a.insert(0, max(0, (int)(b.size() - a.size())), '0');
    b.insert(0, max(0, (int)(a.size() - b.size())), '0');
    for(int i = a.size() - 1; i >= 0; --i){
        mid = a[i] - '0' + b[i] - '0' + du;
        du = mid / 10;
        res = (char)(mid % 10 + 48) + res;
    }
    if(du > 0) res = "1" + res;
    return res;
}

string Sub(string a, string b){
    int t = 0;
    if(a < b) {
        swap(a, b);
        t = 1;
    }
    string res = "";
    int du = 0;
    int mid = 0;
    a.insert(0, max(0, (int)(b.size() - a.size())), '0');
    b.insert(0, max(0, (int)(a.size() - b.size())), '0');
    for(int i = a.size() - 1; i >= 0; --i){
        mid = a[i] - '0' - b[i] + '0' - du;
        if(mid < 0){
            mid += 10;
            du = 1;
        } 
        else du = 0;
        res = char(mid % 10 + '0') + res;
    }
    while(res[0] == '0' && res.size() > 1) res.erase(0, 1);
    if(t == 1) res = "-" + res;
    return res;
}
string Mult_Small(string a, int b, int l){
    int du = 0;
    int mid = 0;
    string res = "";
    for(int i = a.size() - 1; i >= 0; --i){
        mid = (a[i] - '0') * b + du;
        du = mid / 10;
        res = (char)(mid % 10 + '0') + res;
    }
    if(du > 0){
        res = to_string(du) + res;
    }
    res.insert(res.size(), l, '0');
    return res;
}
string Mult_Big(string a, string b){
    string res = "";
    for(int i = b.size() - 1; i >= 0; --i){
        string tmp = Mult_Small(a, b[i] - '0', b.size() - i - 1);
        res = Add(res, tmp);
    }
    return res;
}
void solve(){
    string a, b;
    cin >> a >> b;
    cout << Add(a, b) << endl;
    cout << Sub(a, b) << endl;
    cout << Mult_Big(a, b);
}
signed main() {
    faster();
    file();
    solve();
}
