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
const int MAX = 1e6 + 5;
string s = "ABC";
int n;
void BackTracking(int n, int a, int b, int c){
    if(n == 1) {
        cout << s[a] << " " << s[b] << endl;
        return;
    }
    BackTracking(n - 1, a, c, b);
    cout << s[a] << " " << s[b] << endl;
    BackTracking(n - 1, c, b, a);

}
void solve(){
    cin >> n;
    BackTracking(n, 0, 2, 1);
}
int main(){
    file();
    faster();
    solve();
}