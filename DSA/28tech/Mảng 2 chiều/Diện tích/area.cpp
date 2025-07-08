#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[505][505];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int d = 0, mx = 0;
void loang(int i, int j)
{
    d++;
    a[i][j] = 0;
    for(int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 && j1 >= 0 && i1 < n && j1 < m && a[i1][j1] == 1) 
        {
            loang(i1, j1);
        }
    }
}

int main()
{
    cin >> n >> m; 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 1)
            {
                d = 0;
                loang(i, j);
                mx = max(mx ,d);
            }
        }
    }
    cout << mx;
}