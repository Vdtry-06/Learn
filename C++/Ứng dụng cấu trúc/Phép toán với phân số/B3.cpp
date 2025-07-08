#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct PhanSo
{
    ll tu, mau;
};
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
void process(PhanSo &A, PhanSo &B)
{
    ll g = gcd(A.tu, A.mau);
    A.tu /= g;
    A.mau /= g;
    ll g1 = gcd(B.tu, B.mau);
    B.tu /= g1;
    B.mau /= g1;
    ll t = A.tu * B.mau + A.mau * B.tu;
    ll m = A.mau * B.mau;
    ll g2 = gcd(t, m);
    t /= g2;
    m /= g2;
    cout << t * t << "/" << m * m << " ";
    ll t1 = A.tu * B.tu * t * t;
    ll m1 = A.mau * B.mau * m * m;
    ll g3 = gcd(t1, m1);
    t1 /= g3;
    m1 /= g3;
    cout << t1 << "/" << m1 << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}