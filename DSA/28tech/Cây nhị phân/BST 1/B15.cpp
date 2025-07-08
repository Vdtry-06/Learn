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
};
node *makenode(int x)
{
    node *n_n = new node;
    n_n->data = x;
    n_n->left = NULL;
    n_n->right = NULL;
    return n_n;
}
node *insert(node *root, int key)
{
    if(root == NULL) return makenode(key);
    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}
bool search(node *root, int key)
{
    if(root == NULL) return false;
    if(root->data == key) return true;
    else if(root->data < key) return search(root->right, key);
    return search(root->left, key);
}
void inorder(node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void input()
{
    node *root = NULL;
    int n; cin >> n;
    FOR(i, 0, n)
    {
        int x; cin >> x;
        if(!root) 
        {
            root = makenode(x);
        }
        else insert(root, x);
    }
    inorder(root);
}
signed main()
{
    // file();
    faster();
    input();
}
