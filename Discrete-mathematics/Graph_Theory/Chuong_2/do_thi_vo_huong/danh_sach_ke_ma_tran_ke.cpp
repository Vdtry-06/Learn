#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<int> adj[1005];
int a[1005][1005];
int n;
void solve(){
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> num){
            a[i][stoi(num)] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    // file();
    faster();
    solve();
}