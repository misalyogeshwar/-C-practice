#include <iostream>
#include<stdlib.h> // for exit(0)

using namespace std;

struct node {
	int data;
	struct node * next;
};

struct node* create_new_node(int val)
{
 struct node*new_node = new node;
 new_node->data = val;
 new_node->next = NULL;
 return new_node;
}

void push(struct node ** head_ref,int val)
{
    struct node* new_node = create_new_node(val);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display(struct node*temp)
{
    while(temp->next!= NULL)
    {
        cout << "\t" << temp->data ;
        temp = temp->next;
    }
}
void add_two_list(struct node* list1,struct node* list2, struct node ** res)
{
int i = 0;
    while (i < 3) //&& - logical and  & - bitwise and
    {
        cout<<"inside**********\n";

        struct node *new_node = create_new_node(list1->data + list2->data);
        list1 = list1 -> next;
        list2 = list2 -> next;
        new_node->next = (*res);
        (*res) = new_node;
        i++;

    }
}
int main() {
	// your code goes here
//    int data;
    struct node *head1= new node;
    head1->next = NULL;
    struct node* head2 = new node;
    head2->next = NULL;

    struct node*res = new node;
    res->next = NULL;
    push(&head1,1);
    push(&head1,2);
    push(&head1,3);

    push(&head2,4);
    push(&head2,5);
    push(&head2,6);
    cout<<"\n \tFirst list is  : ";
    display(head1);
    cout<<"\n\tsecond list is  : ";
    display(head2);

    add_two_list(head1,head2,&res);
    cout<<"\n\tresult list is  : ";
    display(res);

//    while(1)
//    {
//        cout << "\n***************";
//        cout << "\n1.Say Hello ";
//        cout << "\n2.Insert into list ";
//        cout << "\n3.Display list";
//        cout << "\n4.exit";
//        cout << "\nEnter your choice > ";
//        cin >> data;
//        switch(data)
//            {
//            case 1:
//                cout << "Hello yogeshwar";
//                break;
//            case 2:
//                cout << "insert data";
//                int val;
//                cin>>val;
//                push(&head1,val);
//                break;
//            case 3:
//                display(head1);
//                break;
//            case 4:
//                cout << "Bye Bye";
//                exit(0);
//            }
//    }

	return 0;
}
