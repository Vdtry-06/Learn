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
int check;
int n, k;
void init(){
    FOR(i, 1, n) a[i] = i;
}
void sinh(){
    int i = n;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) check = 0;
    else{
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1);
    }
}
void solve(){
    cin >> n;
    cout << n;
    // init();
    // check = 1;
    // while(check){
    //     FOR(i, 1, n) cout << a[i] << " ";
    //     cout << endl;
    //     sinh();
    // }
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