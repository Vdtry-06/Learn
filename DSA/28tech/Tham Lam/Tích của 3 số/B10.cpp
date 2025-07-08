#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, d = 0;
int main()
{
    cin >> n;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            if(n / i != i)
            {
                d++;
                //cout << i << endl;
            }
            n /= i;
        }
    }
    // cout << n;
    if(n > 1) d++;
    if(d >= 3) cout << "YES";
    else cout << "NO";
}