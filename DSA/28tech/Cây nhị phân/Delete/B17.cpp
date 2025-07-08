#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
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
node *minnode(node *root)
{
    node *tmp = root;
    while(tmp != NULL && tmp->left != NULL)
    {
        tmp = tmp->left;   
    }
    return tmp;
}
node *deletenode(node *root, int key)
{
    if(root == NULL) return root;
    if(key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        if(root->left == NULL)
        {
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == NULL)
        {
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        else 
        {
            node *tmp = minnode(root->right);
            root->data = tmp->data;
            root->right = deletenode(root->right, tmp->data);
        }
    }
    return root;
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
        if(!root) root = makenode(x);
        else insert(root, x);
    }
    int key;
    cin >> key;
    root = deletenode(root, key);
    inorder(root);
}
signed main()
{
    // file();
    faster();
    input();
}
