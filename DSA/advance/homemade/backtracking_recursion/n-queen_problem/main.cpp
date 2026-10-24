#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e18;
const int MAX = 105;
int n;
vector<vector<int>> res;
int used[MAX][MAX];

bool check(int i, int j) {

    for (int x = i - 1; x >= 0; x--) {
        // Cùng cột
        if (used[x][j]) return false;

        // Đường chéo trên-trái
        int l = j - (i - x);
        if (l >= 0 && used[x][l]) return false;

        // Đường chéo trên-phải
        int r = j + (i - x);
        if (r < n && used[x][r]) return false;
    }

    return true;
}

void backtrack(int i, int j, vector<int> &ans) {
    // danh dau
    used[i][j] = true;
    ans.push_back(j);

    // ket thuc
    if (ans.size() == n) {
        res.push_back(ans);
        ans.pop_back();
        used[i][j] = false;
        return;
    }

    // thu lua chon
    for (int col = 0; col < n; col++) {
        if (!check(i + 1, col)) continue;

        backtrack(i + 1, col, ans);
    }

    ans.pop_back();
    used[i][j] = false; 
}

void solve () {
    cin >> n;
    
    memset(used, false, sizeof(used));

    vector<int> ans;
    
    for (int j = 0; j < n; j++) {
        backtrack(0, j, ans);
    }

    for (vector<int> x : res) {
        for (int val : x) {
            cout << val + 1 << " ";
        }
        cout << endl;
    }

    cout << endl;

    res.clear();
}


int main() {
    file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}
