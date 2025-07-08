#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main()
{
    cin >> n;
    ll mi = INT_MAX, s7 = 0, check = 0;
    for(int i = 0; i <= n / 7; i++)
    {
        if((n - 7 * i) % 4 == 0)
        {
            check = 1;
            if(mi > (n - 7 * i) / 4)
            {
                mi = (n - 7 * i) / 4;
                s7 = i;
            }
        }
    }
    if(check == 0) 
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < mi; i++) cout << 4;
    for(int i = 0; i < s7; i++) cout << 7;
    
}