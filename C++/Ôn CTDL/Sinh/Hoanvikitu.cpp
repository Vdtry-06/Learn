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
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
void solve(){
    char a, b;
    cin >> a >> b;
    int x = a - 64;
    int y = b - 64;
    if(x > y) swap(x, y);
    string s = "";
    for(int i = x; i <= y; i++){
        s += char(i + 64);
    }
    do{
        for(int i = 0; i < s.size(); i++) cout << s[i];
        cout << endl;
    } while(next_permutation(s.begin(), s.end()));
}
int main(){
    // file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}