#include <bits/stdc++.h>

using namespace std;

int L(int n)
{
    if(n ==1)
    {
        return 1;
    }

    return L(n/2)*n ;
}


int main()
{
    cout << L(25) << endl;
}