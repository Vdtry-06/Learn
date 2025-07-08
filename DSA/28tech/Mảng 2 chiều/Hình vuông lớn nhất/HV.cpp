#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1E9+7;
const int MAX = 1e6+5;
int dx[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int dy[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
int a[205][205], f[205][205];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int s = 0, mx = - INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            s = 0;
            for(int k = 0; k < 9; k++)
            {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if(i1 >= 0 && j1 >= 0; i1 < n && j1 < n)
                {
                    s += a[i1][j1];
                }
            }
            mx = max(mx, s);
        }
    }
    cout << mx;
}