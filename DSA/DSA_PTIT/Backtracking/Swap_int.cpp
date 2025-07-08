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
string s, res;
int k;
void BackTracking(string s, int k){
    if(k == 0) return;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(s[i] < s[j]){
                swap(s[i], s[j]);
                res = max(res, s);
                BackTracking(s, k - 1);
                swap(s[i], s[j]);
            }
        }
    }
}
void solve(){
    string s;
    cin >> k >> s;
    res = s;
    BackTracking(s, k);
    cout << res;
}
int main(){
    file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    } 
}