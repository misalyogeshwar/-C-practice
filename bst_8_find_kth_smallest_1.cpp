#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int key;
    node * left , *right;
};

node * newNode(int key)
{
    node * temp = new node();
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node * insert(node * Node,int key)
{
    if(Node == NULL){ return newNode(key);}
    else if(key > Node->key)
        Node->right = insert(Node->right,key);
    else
        Node->left = insert(Node->left,key);
}

void find_kth_recursive(node * root,int k)
{
    static int count = 0;
    if(root != NULL)
    {
        find_kth_recursive(root->left,k);
        count ++;
        if(count == k)
            {cout << "\t" << root->key;
               return;
            }
        find_kth_recursive(root->right,k);
    }
}

void find_kth_iterative(node * root,int k)
{
    stack <node *> st;
    int count = 0;

    if(root == NULL)
        return;
    else
    {
        while(1)
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }

        root = st.top();
        st.pop();
        count++;
        if(count == k)
        {
            cout << "\t" << root->key;
            return;
        }

        if(root->right != NULL)
            root = root->right;
        else
            root = NULL;
    }
}
}
int main()
{
    cout << "Hello world!" << endl;
    node * root = NULL;
    root = insert(root,100);
    insert(root,78);
    insert(root,8);
    insert(root,7);
    insert(root,4);
    insert(root,5);
    insert(root,200);
    insert(root,150);
    insert(root,300);

    find_kth_recursive(root,9);
    find_kth_iterative(root,9);
    return 0;
}
