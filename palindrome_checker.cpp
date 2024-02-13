#include <iostream>
using namespace std;

struct node{
    char data;
    node* next;

    node(char d)
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

    void push(char data)
    {
        node* temp = new node(data);
        
        temp -> next = top;
        top = temp;


    }

    char pop()
    {
        node* temp = top;
        top = top-> next;
         delete(temp);
        return top -> data;
       
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


struct QNode
{
    char data;
    QNode* next;

    QNode(char d)
    {
        data = d;
        next = NULL;
    }
};

struct  Queue{

    QNode* front ;
    QNode* rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(char d)
    {
            QNode* temp = new QNode(d);

            if(rear == NULL)
            {
                front = rear = temp;
                return;
            }

            rear->next = temp;
            rear = temp;

    }


    char dequeue()
    {
        if(front == NULL)
        {
            cout << "The Queue is empty!" << endl;
            return;
        }

        QNode* temp = front;
        front = front->next;

        if(front == NULL) rear = NULL;
        delete(temp);
        return rear-> data;

        
    }

    void print()
    {
        QNode* temp = front;
        while (temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }

        cout << endl;
        
    }

};


int main()
{
    
}