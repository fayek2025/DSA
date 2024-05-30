#include <bits/stdc++.h>

using namespace std;


void countsort(int arr[] , int n)
{
    int max = *max_element(arr , arr+n);
    int min = *min_element(arr , arr+n);

    int freq = max-min + 1;
    int countarray[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = arr[i] - min;
        countarray[index]++;
    }
    int arrayindex = 0;
    for (int index = 0; index < freq; index++)
    {
        while (countarray[index] > 0)
        {
            arr[arrayindex] = index + min;
            countarray[index]--;
            arrayindex++;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return;
    

}

int main()
{
    int n;
    int arr[1000] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    countsort(arr , n);
    
}