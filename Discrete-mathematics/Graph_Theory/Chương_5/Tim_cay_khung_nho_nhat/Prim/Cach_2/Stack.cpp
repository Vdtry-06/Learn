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
    int x, y;
    int w;
};

int n, m;
vector<pr> ke[1005];
int parent[1005];
// int d[1005];
bool used[1005];

void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
    // for(int i = 1; i <= n; i++) d[i] = MAX;
}

void Prim(int u){
    priority_queue<pr, vector<pr>, greater<pr>> Q; // hang doi min
    vector<canh> MST; // cay khung
    int res = 0; // do dai cay khung
    Q.push({0, u}); // day dinh u vao hang doi
    while(!Q.empty()){
        pr top = Q.top(); Q.pop(); // lay tk dao tien cua hang doi
        int W = top.fi; // trong so
        int dinh = top.se; // dinh
        if(used[dinh]) continue; // dinh da duoc vao V(MST) thi bo qua
        res += W; // tong trong so
        used[dinh] = true; // dua dinh vao V(MST)
        if(u != dinh){ // khac dinh dau tien
            MST.push_back({dinh, parent[dinh], W}); // luu vao V(MST) dinh, cha cua dinh, va trong so
        }
        // duyet tat ca cac dinh ke
        for(auto it : ke[dinh]){
            int x = it.fi; // x : dinh ke cua "dinh"
            int trong_so = it.se; // trong so
            // neu x chua duoc luu vao V(MST) va trong so min theo tung dinh x
            // if(!used[x] && trong_so < d[x]){
            if(!used[x]){
                Q.push({trong_so, x});// day trong so va dinh x vao hang doi
                // d[x] = trong_so;
                parent[x] = dinh; // cha cua dinh x la "dinh"
            }
        }
    }
    cout << res << endl;
    for(canh x : MST) cout << x.x << " " << x.y << " " << x.w << endl;
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