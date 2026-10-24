#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 1e18;
const int MAX = 105;
int n;
vector<vector<int>> res;
bool col[MAX];
bool dia1[2 * MAX];
bool dia2[2 * MAX];

bool check(int i, int j) {
    return !col[j] && !dia1[i - j + n - 1] && !dia2[i + j];
}

void backtrack(int i, int j, vector<int> &ans) {
    // Đánh dấu vị trí quân hậu
    col[j] = dia1[i - j + n - 1] = dia2[i + j] = true;

    ans.push_back(j);

    // ket thuc
    if (ans.size() == n) {
        res.push_back(ans);
        ans.pop_back();

        col[j] = dia1[i - j + n - 1] = dia2[i + j] = false;

        return;
    }

    // thu lua chon
    for (int col = 0; col < n; col++) {
        if (!check(i + 1, col)) continue;

        backtrack(i + 1, col, ans);
    }

    ans.pop_back();
    col[j] = dia1[i - j + n - 1] = dia2[i + j] = false;
}

void solve () {
    cin >> n;
    
    memset(col, false, sizeof(col));
    memset(dia1, false, sizeof(dia1));
    memset(dia2, false, sizeof(dia2));

    vector<int> ans;
    
    for (int j = 0; j < n; j++) backtrack(0, j, ans);

    for (vector<int> x : res) {
        for (int val : x) cout << val + 1 << " ";
        cout << endl;
    }

    cout << endl;

    res.clear();
}


int main() {
    // file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}
