#include <bits/stdc++.h>


using namespace std;

bool isPalindrome(string s , int i , int e)
{
    if(i == e)
    {
        return true;
    }

    if(s[i] != s[e])
    {
        return false;
    }

    if(i < e+1)
    {
        return isPalindrome(s , i+1 , e-1);
    }

    return true;
    
}


int main()
{
    string str = "geeg";
    int i = 0;
    int size = str.size();
    
 
    if (isPalindrome(str , i , size-1))
    cout << "Yes";
    else
    cout << "No";
 
    return 0;
}
 