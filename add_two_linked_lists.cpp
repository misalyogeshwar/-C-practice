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

void display_special(struct node *temp)
{
    if (temp->next!=NULL)
        display_special(temp->next);

    cout << "\t"<<temp->data;
}
void add_two_list(struct node* list1,struct node* list2, struct node ** res)
{
int i = 0;
int carry = 0;
int flag = 0;
 //   while (list1->next != NULL or list2->next != NULL or carry  > 0) //&& - logical and  & - bitwise and
   while( i <4)
    {
        int sum = 0;

        if(list1->next != NULL and list2->next!=NULL)
            sum = list1->data + list2->data+ carry;
        else if(list1->next == NULL and list2->next != NULL)
            sum = list2->data + carry;
        else if(list2->next == NULL and list1->next!=NULL)
            sum = list1->data + carry;
        else
        {   sum = carry;
            if (flag == 1)
            {
                carry = 0;
            }

        }

        if (sum > 10)
        {
            int total;
            total = sum;
            sum = sum%10;
            carry = total/10;
        }
        else if(sum == 10)
        {
            sum = 0;
            carry = 1;
            flag =1;
        }
        else{carry = 0;
            }

        struct node *new_node = create_new_node(sum);
           new_node->next = (*res);
        (*res) = new_node;
        list1 = list1 -> next;
        list2 = list2 -> next;
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
    push(&head1,4);
    push(&head1,5);
    push(&head1,5);

    push(&head2,6);
    push(&head2,7);
    push(&head2,7);
    cout<<"\n \tFirst list is  : ";
    display(head1);
    cout<<"\n\tsecond list is  : ";
    display(head2);

    add_two_list(head1,head2,&res);
      cout<<"\n\t                      ________________________";
    cout<<"\n\n\tresult list is  : ";
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
