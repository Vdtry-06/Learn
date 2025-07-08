#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
typedef priority_queue<int, vector<int>, greater<int>> pq_min;
typedef pair<int, pair<int, int>> prr;
typedef priority_queue<ll> pq_max;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
#define fi first 
#define se second
#define sze size()
#define endl '\n'
struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    } 
};
void makenode(node *root, int x, int y, char z)
{
    if(z == 'L') root->left = new node(y);
    else root->right = new node(y);
}
void insert(node *root, int x, int y, char z)
{
    if(root == NULL) return;
    if(root->data == x) makenode(root, x, y, z);
    else
    {
        insert(root->left, x, y, z);
        insert(root->right, x, y, z);
    }
}
bool check(node *root1, node *root2)
{
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->data != root2->data) return false;
    return check(root1->left, root2->left) && check(root1->right, root2->right);
}
void input(node *&root)
{
    int n; cin >> n;
    FOR(i, 0, n)
    {
        int x, y; char z;
        cin >> x >> y >> z;
        if(!root) 
        {
            root = new node(x);
            makenode(root, x, y, z);
        }
        else insert(root, x, y, z);
    }
}
signed main()
{
    // file();
    faster();
    node *root1 = NULL, *root2 = NULL;
    input(root1); 
    input(root2);
    if(check(root1, root2)) cout << "YES";
    else cout << "NO";
}
