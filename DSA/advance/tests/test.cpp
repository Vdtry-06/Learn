#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int INF = 1e9;
const int MAX = 105;
char a[MAX][MAX];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;

struct State {
    int x, y;
    int hasKey;
};

int dis[MAX][MAX][2];
bool used[MAX][MAX][2];
queue<State> q;

void BFS(int i, int j) {

    int startKey = (a[i][j] == 'a');
    
    q.push({i, j, startKey});
    dis[i][j][startKey] = 0;
    used[i][j][startKey] = true;

    int ex = -1, ey = -1, ekey = -1;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        int x = cur.x;
        int y = cur.y;
        int hasKey = cur.hasKey;

        if (a[x][y] == 'O') {
            ex = x;
            ey = y;
            ekey = hasKey;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (a[nx][ny] == 'X') continue;

            if (a[nx][ny] == 'A' && hasKey == 0) continue;

            int nextKey = hasKey;

            if (a[nx][ny] == 'a') nextKey = 1;

            if (used[nx][ny][nextKey]) continue;

            used[nx][ny][nextKey] = true;
            dis[nx][ny][nextKey] = dis[x][y][hasKey] + 1;
            q.push({nx, ny, nextKey});
        }
    }
    if (ex == -1) cout << -1 << endl;
    else cout << dis[ex][ey][ekey] << endl;
}


void solve() {
    cin >> n >> m;
    int r, c; cin >> r >> c;
    r--;
    c--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(used, false, sizeof(used));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                dis[i][j][k] = INF;
            }
        }
    }

    BFS(r, c);
    while(!q.empty()) q.pop();
}

int main() {
    file();
    faster();
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "#" << i << ": ";
        solve();
    }
}