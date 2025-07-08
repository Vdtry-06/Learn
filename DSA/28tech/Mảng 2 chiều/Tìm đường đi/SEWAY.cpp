#include<bits/stdc++.h>
using namespace std;
int x[4] = {-1, 0, 0, 1};
int y[4] = {0, -1, 1, 0};
int a[105][105];
int s, t, u, v;
int n, m;
void loang(int i, int j)
{
    a[i][j] = 0;
    for(int k = 0; k < 4; k++) 
    {
        int i1 = i + x[k];
        int j1 = j + y[k];
        if(i1 >= 0 && j1 < n && i1 >= 0 && j <= m && a[i1][j1] == 1)
        {
            loang(i1, j1);
        }
    }
}
int main()
{
    cin >> n >> m;
    cin >> s >> t >> u >> v;
    s--; t--; u--; v--;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int check = a[u][v];
    if(a[s][t]) 
    {
        loang(s, t);
        if(a[u][v] == 0 && check) cout << "YES";
        else cout << "NO";
    }
    else cout << "NO";
}