#include <bits/stdc++.h>

using namespace std;


void combination(int arr[] , int data[] , int start , int end , int index , int r)
{
    if(index == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        return;
        
    }

    for (int i = start; i <= end ; i++)
    {
        data[index] = arr[i];
        combination(arr , data , i+1 , end , index+1 , r );
    }
    
}


int main()
{
    int arr[] = {1,2,3,4};

    int data[3] = {0};

    int r = 3;
    combination(arr , data , 0 , 3 , 0 , r);
}