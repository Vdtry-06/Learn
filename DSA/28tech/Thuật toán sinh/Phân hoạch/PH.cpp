#include<bits/stdc++.h>
using namespace std;
int n, a[100], ans = 0;
vector<string> v;
bool check;
int cnt;
void ktao()
{
    cnt = 1; // so phan tu
    a[1] = n;
}
void sinh()
{
    int i = cnt;
    while(i >= 1 && a[i] == 1) i--;
    if(i == 0) check = 0;
    else // a[i] > 1
    {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];
        if(q)
        {
            for(int j = 1; j <= q; j++)
            {
                cnt++;
                a[cnt] = a[i];
            }
        }
        if(r)
        {
            cnt++;
            a[cnt] = r;
        }
    }
}
int main()
{
    cin >> n;
    ktao();
    check = 1;
    while(check)
    {
        ans++;
        string s = "";
        for(int i = 1; i <= cnt; i++)
        {
            s += to_string(a[i]);
            if(i < cnt) s += "+";
        }
        v.push_back(s);
        sinh();
    }
    cout << ans << endl;
    for(auto x : v) cout << x << endl;
}