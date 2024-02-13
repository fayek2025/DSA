#include <iostream>

using namespace std;

#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data)
{
    if(top == MAX -1)
    {
        cout << "Stack is full!" << endl;
        return;
    }
    top++;
    stack_arr[top] = data;
}


int pop()
{
    int value;
    value = stack_arr[top];
    top --;
    if(top <= 0)
    {
        cout << "Stack is empty1" << endl;
        exit(1);
    }
    return value;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    //push(5);
    pop();

    for (int i = 0; i <= top; i++)
    {
        cout << stack_arr[i] << " ";
    }
    cout << endl;
    

}