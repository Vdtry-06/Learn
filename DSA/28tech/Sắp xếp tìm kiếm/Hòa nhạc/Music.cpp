#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() 
{
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; i++) 
    {
        int x; cin >> x;
        ms.insert(x);
    }
    while(m--)
    {
        int x; cin >> x;
        auto it = ms.upper_bound(x);
        if(it != ms.begin())
        {
            it--;
            cout << *it << endl;
            ms.erase(it);
        }
        else cout << -1 << endl;
    }
}