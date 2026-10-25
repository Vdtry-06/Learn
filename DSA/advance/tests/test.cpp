#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int INF = 1e9;
const int MAX = 205;
int a[MAX];
int n, s;
int dp[MAX][100005];

bool backtrack(int idx, int sum) {
    // 2. hoan thanh
    if (sum == 0) return true;

    // cat nhanh
    if (idx < 0 || sum < 0) return false; 

    // neu trang thai da dc tinh
    if (dp[idx][sum] != -1) return dp[idx][sum];

    // 3. chon
    if (sum >= a[idx]) {
        if (backtrack(idx - 1, sum - a[idx])) return dp[idx][sum] = 1;
    }

    // 4. ko chon
    if (backtrack(idx - 1, sum)) return dp[idx][sum] = 1;

    // 5. that bai
    return dp[idx][sum] = 0;
}

void solve () {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    
    sort(a, a + n);

    if (backtrack(n - 1, s)) cout << 1;
    else cout << 0;
    cout << endl;
}

int main() {
    file();
    faster();
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << " ";
        solve();
    }
}