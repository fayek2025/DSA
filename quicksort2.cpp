#include <bits/stdc++.h>

using namespace std;


void quicksort(int arr[] , int  start , int end)
{
    int pivot = partition(arr , start , end);

    quicksort(arr , start , pivot-1);
    quicksort(arr , pivot+1 , end);
}


int partition(int arr[] ,int start ,int end)
{
    int pivot = arr[end];

    int i = start-1;
    int j = start;

    for (j; j<= end-1; j++)
    {
        if(arr[i] < pivot)
        {
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    i++;
    swap(arr[i] , arr[j]);

    return i;
    



}


int main()
{
    int arr[] = {100, 50 , 91 , 45 , 80 , 60 , 110 , 45};
    int start = 0;
    int end = 7;

    quicksort(arr , start , end);

    for (int i = 0; i < end+1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}