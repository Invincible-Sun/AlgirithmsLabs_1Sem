#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream fin("antiqs.in");
    ofstream fout("antiqs.out");

    int n;
    fin >> n;
    int array[n];

    for(int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }

    for(int i = 0; i < n; i++)
    {
        swap(array[i], array[i / 2]);
    }
    for(int i = 0; i < n; i++)
    {
        fout << array[i] << " ";
    }
    fin.close();
    fout.close();
}
