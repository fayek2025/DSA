#include<bits/stdc++.h>

using namespace std;

void countsort(int exp , int arr[] , int n)
{
    int countarray[10] = {0};
    int outputarray[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        countarray[(arr[i]/exp) % 10]++;
    }


    for (int i = 1; i < 10; i++)
    {
        countarray[i] += countarray[i-1];
    }

    for (int i = n-1; i >= 0; i++)
    {
        outputarray[(countarray[(arr[i]/exp) % 10]) - 1] = arr[i];

        countarray[(arr[i]/exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = outputarray[i];
    }
    
    
    
    
}


void radixsort(int arr[] , int n)
{
    int maximum = *max_element(arr , arr+n);

    for (int i = 1; maximum/i > 0 ; i *= 10)
    {
         countsort(i , arr , n);
    }
    

}

void print(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    
}