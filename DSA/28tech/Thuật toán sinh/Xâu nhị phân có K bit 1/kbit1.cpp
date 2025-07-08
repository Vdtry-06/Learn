#include<bits/stdc++.h>
using namespace std;
vector<string> v1, v2;
int n, k, a[100];
bool check;
void ktao()
{
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh()
{
    int i = n; 
    while(i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if(i == 0) check = 0;
    else a[i] = 1;
}
bool ck1()
{
    int d = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1) d++; 
    }
    return d == k;
}
bool ck2()
{
    int cnt = 0;
    int f[n];
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1) 
        {
            if(i == 1) f[i] = 1;
            f[i] = f[i - 1] + 1;
        }
        else f[i] = 0;
        if(f[i] == k) cnt++;
        else if(f[i] > k) return 0; 
    }
    return cnt == 1;
}
int main()
{
    cin >> n >> k;
    ktao();
    check = 1;
    while(check)
    {
        if(ck1())
        {
            string s1;
            for(int i = 1; i <= n; i++)
            {
                s1 += to_string(a[i]);
            }
            v1.push_back(s1);
            s1.clear();
        }
        if(ck2())
        {
            string s2;
            for(int i = 1; i <= n; i++)
            {
                s2 += to_string(a[i]);
            }
            v2.push_back(s2);
            s2.clear();
        }
        sinh();
    }
    for(auto x : v1) cout << x << " ";
    cout << endl;
    for(auto x : v2) cout << x << " ";
}