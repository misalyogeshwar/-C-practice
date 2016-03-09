#include <iostream>
using namespace std; // consider removing this line in serious projects
static int i = 0;

struct node {
	int data;
	struct node * next;
};

void insert_list(int num,struct node* root)
{
	struct node * new_node;
	while((root -> next)!= NULL)
		root->next;

	root->next= new_node;
	new_node->data = num;
	new_node->next = NULL;
}

void display_list(node* root)
{
	while(root->next!= NULL)
		cout<<root->data<<"\n";
		root = root->next;
}

int main() {
	int intNum = 0;
	node *root;

	root = new node;
	root->next=NULL;
	root->data = 0;

	cout << &root;
	cout<<"\n";
	cout<<root;


	while(cin >> intNum)
	{
		cout<<"******"<<intNum<<"\n";
		insert_list(intNum,root);
	}

	display_list(root);

	return 0;
}
