#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

void push(struct node** head , int data)
{
    struct node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode-> next = *head;
        *head = newnode;
    }

}

int  pop(struct node** head)
{
    node* temp = *head;
    *head = temp->next;
    return temp->data;
    free(temp);
}

int main()
{
    
}