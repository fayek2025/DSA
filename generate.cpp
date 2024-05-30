#include <Bits/stdc++.h>
using namespace std;

void generate(string word , int length , int count_A)
{

    if(length > 5)
    {
        if(count_A > 4)
        {
            cout << word << endl;
            cout << length << endl;
        }

        return;
    }
    char alpha[3] = {'A','B','C'};

    for (char value : alpha)
    {
        if(value == 'A')
        {
            word = word+value;
            length++;
            count_A++;
            generate(word , length , count_A );
        }
        else
        {
            word = word+value;
            length++;
            
            generate(word , length , count_A );

        }
    }
    

}

int main()
{
    generate("" , 0 , 0);
}