#include <iostream>

using namespace std;

#define n 20

class queue{
    int* arr;
    int font ;
    int back ;


    public:
    queue()
    {
        arr = new int[n];
        font = -1;
        back = -1;

    }


    //enqueue

    void push(int a)
    {
        if(back == n-1)
        {
            cout << "Queue Overflow!" << endl; 
        }
        if(font == -1)
        {
            font++;
            
        }

        
            back++;
            arr[back] = a;
        
    }


    void pop()
    {
        if(font == -1 || font > back)
        {
            cout << "The Queue is empty!" << endl;
            return;
        }
        else
        {
            font++;
        }
    }


    int peek()
    {
        if(font == -1 || font > back)
        {
            cout << "The Queue is Empty!" << endl;
            return 0;
        }

        return arr[font];

    }

    void print()
    {
        int begin = font;
        int end = back;

        for (int i = font; i <= back; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
        
    }

};

int main()
{
    queue line;
    line.push(1);
    line.push(2);

    line.print();
}