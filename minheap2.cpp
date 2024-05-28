#include <bits/stdc++.h>

using namespace std;

int maximum = 1000;

void minheapify(int arr[] , int i , int n)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[smallest] > arr[left] )
    {
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(arr[smallest] , arr[i]);
        minheapify(arr , smallest , n);
    }

}

void buildheap (int arr[] , int n)
{
    //last leaf node
    int index = (n/2)-1;
    for (int i = index; i >= 0; i--)
    {
        minheapify(arr , i , n);
    }
    
}

void printarray(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main()
{
     int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
     int n = 11;

     buildheap(arr , n);

     printarray(arr, n);

}