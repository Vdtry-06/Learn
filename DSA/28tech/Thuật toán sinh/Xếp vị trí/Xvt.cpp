#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
bool check;
int a[100];
string s[100];
void sinh()
{
    int i = n;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) check = 0;
    else
    {
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        cin >> s[i];
        a[i] = i;
    }
    sort(s + 1,s + n + 1);
    check = 1;
    while(check)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << s[a[i]] << " ";
        }
        cout << endl;
        sinh();
    }
}