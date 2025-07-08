#include<bits/stdc++.h>
using namespace std;
string xuli(int sum, int d)
{
    string s = string(d, '0');
    for(int i = d - 1; i >= 0; i--)
    {
        if(sum > 9)
        {
            s[i] = '9';
            sum -= 9;
        }
        else
        {
            if(i == 0) s[i] = sum + '0';
            else
            {
                s[0] = '1';
                s[i] = sum - 1 + '0';
            }
            break;
        }
    }
    return s;
}
int main()
{
    int s, d;
    cin >> s >> d;
    if(d * 9 < s || (d > 1 && s == 0))
    {
        cout << -1;
        return 0;
    }
    cout << xuli(s, d);
}