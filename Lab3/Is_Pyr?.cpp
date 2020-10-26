#include <iostream>
#include <fstream>
using namespace std;
string is_pyr(const int array[], int n)
{
    for(int i = 0; i < (n - 1) / 2; i++)
    {
        if(array[i] <= array[2 * i + 1] and array[i] <= array[2 * i + 2]);
        else
            return "NO";
    }
    return "YES";

}


int main()
{
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    int n, i;
    fin >> n;

    int array[n];
    for(int i = 0; i < n; i++)
    {
        fin >> array[i];
    }

    fout << is_pyr(array, n);


    fin.close();
    fout.close();

}