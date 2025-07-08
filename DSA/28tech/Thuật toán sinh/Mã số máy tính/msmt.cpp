#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int k, n, a[1000];
bool check;
char c;

void ktao()
{
    for(int i = 1; i <= n; i++) a[i] = 1;
}
void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == n / 2) i--;
    if(i == 0) check = 0;
    else 
    {
        a[i]++;
        for(int j = i + 1; j <= n; j++) a[j] = 1;
    }
}
bool ck()
{
    set<int> se;
    for(int i = 1; i <= n / 2; i++)
    {
        se.insert(a[i]);
    }
    return se.size() == n / 2;
}
int main()
{
    cin >> n;
    n *= 2;
    ktao();
    check = 1;
    while(check)
    {
        if(ck())
        {
            for(int i = 1; i <= n; i++)
            {
                if(i <= n / 2) cout << char(a[i] + 64);
                else cout << a[i];
            }
            cout << endl;
        }
        sinh();
    }
}