#include <fstream>
#include <iostream>
using namespace std;
string array1[10000], new_array[10000];
void radix_sort(int index, int str_q)
{
    int k = 0;
    char additional = 'a';
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < str_q; j++)
        {
            if(array1[j][index] == additional)
            {
                new_array[k] = array1[j];
                k++;
            }
        }
        additional++;
    }
    for(int i = 0; i < str_q; i++)
        array1[i] = new_array[i];
}




int main()
{
    ifstream fin("radix.in");
    ofstream fout("radix.out");
    int str_q, len, phases;
    cin >> str_q >> len >> phases;

    for(int i = 0; i < str_q; i++)
       cin >> array1[i];

    for(int i = len - 1; i >= len - phases; i--)
    {
       radix_sort(i, str_q);
    }
    for(int i = 0; i < str_q; i++)
    {
        cout << new_array[i] << "\n";
    }
}