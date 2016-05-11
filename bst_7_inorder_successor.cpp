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

void find_succ(node * root,node * &succ,int key)
{
    if(root == NULL)
        return;
    else
    {
        if(root->key == key)
        {
            node * temp = NULL;
            if(root->right)
            {
                temp = root->right;
                while(temp->left)
                    temp = temp->left;
                succ = temp;
            }

        }
        else if(root->key > key)
        {
            succ = root;
            find_succ(root->left,succ,key);
        }
        else if(root->key < key)
        {
            find_succ(root->right,succ,key);
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    node *root = newNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    node * succ = NULL;
    // always make sure key is present or not in the tree;
    find_succ(root,succ,20);
    if(succ!= NULL){cout << "\n\t Successor is : "<<succ->key;}
    else
        cout <<"\n\t Succ not present";
    return 0;
}
