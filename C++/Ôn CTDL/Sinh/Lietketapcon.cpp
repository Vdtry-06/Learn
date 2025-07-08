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
int a[1005];
int n;
bool check;
void init(){
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) check = false;
    else{
        a[i] = 1;
    }
}
void solve(){
    cin >> n;
    int b[n + 1];
    for(int i = 1; i <= n; i++) cin >> b[i];
    init();
    check = true;
    set<string> se;
    while(check){ 
        string s = "";
        for(int i = 1; i <= n; i++){
            if(a[i] != 0){
                s += to_string(b[a[i] + i - 1]); 
            }
        }  
        se.insert(s);
        s.clear();
        sinh();
    }
    for(string x : se){
        if(x != "") cout << x << endl;
    }
}
int main(){
    // file();
    faster();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    //     cout << endl;
    // }
}