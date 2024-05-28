#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;

};

void push_back(struct node** head , int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node* ptr ;
    ptr = *head;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (ptr -> next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    

}

void push_front(struct node** head , int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node-> next = *head;
    *head = new_node;

}

void printList(struct node* node)
{
    //here initial just node exists
    //there exists no node-> next 
    while (node != NULL)
    {
        cout << node->data << " " ;
        node = node->next;
    }

    cout << endl;
    
}

void add_node_middle(struct node** head , int data , int pos)
{
    struct node* ptr = *head;
    struct node* ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2 -> data = data;
    ptr2 -> next = NULL;
    
    pos--;
    while (1)
    {
        pos--;
        ptr = ptr -> next;
        if(pos <= 1 ) break;
    }

    ptr2 -> next = ptr ->next;
    ptr -> next = ptr2;
     
}

void add_at_position(struct node** head , int data , int pos)
{
    node* current = *head;
    node* newnode = (node*)malloc(sizeof(node));

    if(pos == 0)
    {
        push_front(head , data);
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        current = current -> next;
    }
    newnode->data = data;
    newnode -> next = current->next;
    current->next = newnode;
    return;
    
}


int main()
{
    struct node* head = NULL;

    int  n , k;
    cout << "Insert yout query: " << endl;
    cout << "1.Insert node at back of the linked_list" << endl;
    cout << "2.Insert node at front of the linked_list" << endl;

    cin >> k ;

    cout << "Enter size of the linked list" << endl;
    cin >> n;

    switch (k)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            push_back(&head , value);
        }

        
        break;
    case 2:
         for (int i = 0; i < n; i++)
         {
            int value;
            cin >> value;
            push_front(&head , value);
         }
        break;
         
    default:
        break;
    }
    int pos;
    cin >> pos;

    cout << "Before adding data at a position" << endl;

    //add_node_middle(&head , 5 , 5);
    printList(head);
    add_at_position(&head , 6 , pos);
    cout << "After adding data at a position" << endl;
    printList(head);
}