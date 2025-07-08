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

struct canh{
    int u, v;
    int w;
};

vector<pr> ke[1005];
bool used[1005];
int n, m;

void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}

void Prim(int u){
    vector<canh> MST; // cay khung
    int d = 0; // chieu dai cay khung
    used[u] = true; // dua dinh u vao tap V_MST
    while(MST.size() < n - 1){
        // e = (x, y): canh ngan nhat co x thuoc V va Y thuoc V_MST
        int min_w = MAX;
        int X, Y; // luu 2 dinh cua canh e
        for(int i = 1; i <= n; i++){
            // neu dinh i thuoc tap V_MST
            if(used[i]){
                // duyet danh sach ke cua dinh i
                for(pr x : ke[i]){
                    int j = x.fi; // j dinh cua V
                    int W = x.se; // trongso;
                    if(!used[j] && W < min_w){
                        min_w = W;
                        X = j;
                        Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true;
    }
    cout << d << endl;
    for(canh x : MST) cout << x.u << " " << x.v << " " << x.w << endl;
}

void solve(){
    init();
    Prim(1);
}

int main(){
    // file();
    faster();
    solve();
}