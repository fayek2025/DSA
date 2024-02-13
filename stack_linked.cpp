#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next  =NULL;
    }
};

struct stack{
    node* top;

    stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        node* temp = new node(data);
        
        temp -> next = top;
        top = temp;


    }

    void pop()
    {
        node* temp = top;
        top = top-> next;

        delete(temp);
    }

    void print()
    {
        node* temp = top;

        while (temp != NULL)
        {
            cout << temp -> data << " " ;
            temp = temp -> next;
        }

        cout << endl;
        
    }

};

int main()
{
    stack s;

    s.push(20);
    s.push(10);
    s.push(5);
    s.push(100);

    s.pop();

    s.print();
}