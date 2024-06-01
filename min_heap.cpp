#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[] , int n , int i)
{
    int parent = (i-1)/2;

    if(arr[parent] > 0)
    {
        if(arr[i] > arr[parent])
        {
            swap(arr[i] , arr[parent]);

            heapify(arr , n , parent);
        }
    }
}


void insertNode(int arr[] , int &n ,  int index , int key)
{
    arr[index] = key;


    heapify(arr , n , index);
}

void printArray(int arr[] , int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int n ;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        /* code */
        int a;
        cin >> a;
        insertNode(arr , n , i , a);
    }

    printArray(arr , n);


    
}