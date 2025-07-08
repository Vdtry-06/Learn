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
int f[1005][1005];
string s1, s2;
void Dynamic(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    cout << f[n][m];
}
void solve(){
    cin >> s1 >> s2;
    memset(f, 0, sizeof(f));
    Dynamic(s1, s2);
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