#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
#define endl '\n'
const ll LINF = 1e18 + 5;
const ll ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;
vector<string> res;
void solve(){
    string s;
    // cin.ignore();
    while(getline(cin, s)) {
        string tmp;
        vector<string> v;
        stringstream ss(s);
        while(getline(ss, tmp, ',')) {
            v.push_back(tmp);
        }
        swap(v[1], v[2]);
        string ans = "";
        for(int i = 0; i < v.size(); ++i) {
            ans += v[i];
            if(i != v.size() - 1) ans += ",";
        }
        res.push_back(ans);
    }
    for(string x: res) cout << x << endl;
}
signed main() {
    file();
    faster();
    solve();
}
