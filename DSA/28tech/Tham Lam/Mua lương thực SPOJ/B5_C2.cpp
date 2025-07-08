#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, s, m;
int main()
{
    cin >> n >> s >> m;
    int so_ngay_di_cho = s - s / 7;
    int song = s * m;
    if(song > so_ngay_di_cho * n)
    {
        cout << -1;
        return 0;
    }
    cout << (song + n - 1) / n;
}