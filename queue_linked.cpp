#include <bits/stdc++.h>

using namespace std;

struct QNode
{
    int data;
    QNode* next;

    QNode(int d)
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

    void enqueue(int d)
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


    void dequeue()
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
    Queue q;

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.print();
}