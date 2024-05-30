#include <bits/stdc++.h>

using namespace std;

void search(int arr[] , int data , int  i , int count)
{
    if(arr[i] == data)
    {
        cout << "Found" << endl;
        cout << count << endl;
        return;
    }

    search(arr , data , i+1 , count+1);
}

int main()
{
    int arr[] = {1, 2, 3, 4 ,5};
    int data = 5;
    int i = 0;
    int count = 0;
    search(arr , data , i, count);
}