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
// dk: trong so khong am
// O((V + E)* logV)
// Ban đầu đồ thị chứa N đỉnh, mỗi đỉnh sẽ là một
// tập hợp riêng biệt và có đại diện (cha) là chính
// đỉnh đó. Mỗi lần bạn gộp 2 đỉnh lại với nhau,
// tương tự như có một cạnh nối giữa 2 đỉnh này.
int n, m;
int parent[1005];
int sz[1005];
// make_Set
// gan cha cua no la chinh no
void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
// tim cha cua no
int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
// hop cac cha 
bool Union(int a, int b){
    int a = find(a);
    int b = find(b);
    if(a == b) return false;
    else {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
    return true;
}
void solve(){
    make_set();
    cin >> n >> m;
    int cnt = n;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(Union(x,y)) cnt--;
        cout << cnt << endl;
    }
}
int main(){
    // file();
    faster();
    solve();
}