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
int n, m;
int a[1005][1005];
vector<int> ke[1005];
bool used[1005];
void init(){
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> num){
            ke[i].push_back(stoi(num));
        }
    }
    memset(used, false, sizeof(used));
}
void DFS(int u){
    cout << u << " ";
    used[u] = true;
    for(int x : ke[u]){
        if(!used[x]){
            DFS(x);
            used[x] = true;
        }
    }
}
void stplt(){
    int ans = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            ans++;
            cout << "cac dinh thuoc thanh phan lien thong thu " << ans << ": ";
            DFS(i);
            cout << endl;
        }
    }
    cout << "so thanh phan lien thong : " << ans << endl;
}
void solve(){
    init();
    stplt();
}
int main(){
    // file();
    faster();
    solve();
}