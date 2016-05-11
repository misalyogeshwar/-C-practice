#include <iostream>

using namespace std;

struct node
{
    int key;
    node *left,*right;
};

node * newNode(int data)
{
    node * temp = new node();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node * insert(node *node,int data)
{
    if(node == NULL)
        return newNode(data);
    else
    {
        if(node->key > data)
            node->left  = insert(node->left,data);
        else if (node->key < data)
            node->right = insert(node->right,data);
    }
    return node;
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    else
    {
        inorder(root->left);
        cout << "\t"<<root->key;
        inorder(root->right);
    }
}

bool isPresent(int n)
{
    return true;
}

bool isBetween(int n, int a, int b)
{
    return ((a > n && n > b) || (b > n && n > a));
}
node * lca(node * root,int n1,int n2)
{

    if(!(isPresent(n1)) || !(isPresent(n2)))
        return NULL;

    if(root == NULL)
        return NULL;
    else
    {
        if(isBetween(root->key,n1,n2))
            return root;
        else if(root->key > n1 && root->key > n2)
            return lca(root->left,n1,n2);
        else
            return lca(root->right,n1,n2);
    }

    return NULL;
}
int main()
{
    cout << "Hello world!" << endl;
    node *root = newNode(20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);
    inorder(root);
    node * temp = NULL;
    temp = lca(root,4,14);
    if(temp == NULL)
        cout <<"\n\t LCA not present";
    else
        cout << "\n\tLCA is : "<<temp->key;

    return 0;
}
