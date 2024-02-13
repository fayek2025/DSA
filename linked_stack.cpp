#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};

node* top;

void add_begin( int data)
{
     node* new_node = (node*)malloc( sizeof(node));
     
     if(new_node == NULL)
     {
        cout << "Stack Overflow!" << endl;
        exit(1);
     }
     new_node -> data =data;
     new_node -> next = top;
    //  if(head == NULL)
    //  {
    //     head = new_node;
    //     return;
    //  }
     
    // new_node = head;
     top = new_node;

}

void print()

{
    node* temp = top;
    while (temp != NULL)
    {
        cout << temp-> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}
void pop()
{
    node* temp;
    temp = top;
    top = top-> next;

    free(temp);
}


int main()
{
    // node* top = NULL;

    add_begin( 1);
    add_begin( 2);
    add_begin( 3);
    pop();

    print();



}