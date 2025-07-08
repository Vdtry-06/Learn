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
set<int> ke[1005];
int HC[1005];
bool used[1005];
int step[1005];
int n, m;
void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].insert(y);
        ke[y].insert(x);
        step[x]++;
        step[y]++;
    }
    memset(used, false, sizeof(used));
}
// ktra dk
bool check(){
    for(int i = 1; i <= n; i++){
        if(step[i] < n / 2) return false;
    }
    return true;
}
void Hamilton(int pos, int u){
    used[u] = true;
    HC[pos] = u;
    if(pos == n){
        if(ke[u].find(HC[1]) != ke[u].end()){
            HC[++pos] = HC[1];
            for(int i = 1; i <= pos; i++) cout << HC[i] << " ";
            cout << endl;
        }
        return;
    }
    for(int x : ke[u]){
        if(!used[x]){
            Hamilton(pos + 1, x);
            used[x] = false;
        }
    }
    used[u] = false;
}
void solve(){
    init();
    if(check()){
        Hamilton(1, 2);
    }
    else cout << "Khong co chu trinh hamilton";
}
int main(){
    // file();
    faster();
    solve();
}