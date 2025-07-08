#include<bits/stdc++.h>
using namespace std;
bool check;
int a[100];
int n, k;
void ktao()
{
    for(int i = 1; i <= n; i++) a[i] = 1;
}
void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == k) i--;
    if(i == 0) check = 0;
    else
    {
        a[i]++;
        for(int j = i + 1; j <= n; j++)
        {
            a[j] = 1;
        }
    }
}
int main()
{
    cin >> k >> n;
    ktao();
    check = 1;
    while(check)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
}