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
string getPermutation(int n, int k) {
    vector<int> v;
    for(int i = 1; i <= n; i++) v[i] = i;
    int d = 1;
    string s = "";
    do{
        if(d == k){
            for(int x : v){
                s += to_string(x);
            }
            break;
        }
        d++;
    }while(next_permutation(v.begin() + 1, v.end() + 1));
    return s;
}
void solve(){
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k);
}
int main(){
    file();
    faster();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    //     cout << endl;
    // }
}