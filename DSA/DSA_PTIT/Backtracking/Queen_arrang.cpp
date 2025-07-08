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
bool cc[1005], cp[1005], cot[105]; 
int a[100];
int n, cnt = 0;
void init(){
    FOR(i, 1, 100){
        cc[i] = cp[i] = cot[i] = 1;
    }
}
void Try(int i){
    FOR(j, 1, n){
        if(cot[j] && cc[i - j + n] && cp[i + j - 1]){
            cot[j] = cc[i - j + n] = cp[i + j - 1] = 0;
            if(i == n){
                cnt++;
            }
            else Try(i + 1);
            cot[j] = cc[i - j + n] = cp[i + j - 1] = 1;
        }
    }
}
void solve(){
    cnt = 0;
    cin >> n;
    init();
    Try(1);
    cout << cnt;
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