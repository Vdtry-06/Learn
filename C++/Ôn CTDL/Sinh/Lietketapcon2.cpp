#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int a[1005];
int n, k;
bool check;
void init(){
    for(int i = 1; i <= k; i++) a[i] = i;
}
void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(i == 0) check = false;
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}
void solve(){
    cin >> n >> k;
    int b[n + 1];
    init();
    for(int i = 1; i <= n; i++) cin >> b[i];
    check = true;
    set<string> se;
    while(check){
        string s = "";
        for(int i = 1; i <= k; i++){
            s += to_string(b[a[i]]);
        }
        se.insert(s);
        s.clear();
        sinh();
    }
    for(string x: se) cout << x << endl;
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

// CACH 2
// int a[1005];
// int n, k;
// bool check;
// void init(){
//     for(int i = 1; i <= n; i++) a[i] = 0;
// }
// void sinh(){
//     int i = n;
//     while(i >= 1 && a[i] == 1) {
//         a[i] = 0;
//         i--;
//     }
//     if(i == 0) check = false;
//     else{
//         a[i] = 1;
//     }
// }
// void solve(){
//     cin >> n >> k;
//     int b[n + 1];
//     for(int i = 1; i <= n; i++) cin >> b[i];
//     init();
//     check = true;
//     set<string> se;
//     while(check){ 
//         string s = "";
//         int cnt = 0;
//         for(int i = 1; i <= n; i++){
//             if(a[i] != 0){
//                 cnt++;
//                 s += to_string(b[a[i] + i - 1]); 
//                 if(cnt == k) break;
//             }
//         }  
//         if(cnt == k) se.insert(s);
//         s.clear();
//         sinh();
//     }
//     for(string x : se){
//         if(x != "") cout << x << endl;
//     }
// }
// int main(){
//     file();
//     faster();
//     // int t;
//     // cin >> t;
//     // while(t--){
//         solve();
//     //     cout << endl;
//     // }
// }