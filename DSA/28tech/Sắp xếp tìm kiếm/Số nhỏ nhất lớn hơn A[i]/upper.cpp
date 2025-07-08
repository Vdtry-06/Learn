#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 5;
int a[MAX], b[MAX];
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        auto it = upper_bound(a, a + n, b[i]);
        if(it - a == n) cout << "_ ";
        else cout << *it << " ";
    }
}