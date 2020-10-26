#include <iostream>
#include <fstream>
using namespace std;
long long answer = 0, n, new_array[300000], array1[300000];
void merge(long first, long last)
{
    long middle, start, final, j = 0, i = 0;


    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    long inversion = middle - first + 1;

    while(start + i <= middle && final + j <= last)
    {
        if(array1[start + i] <= array1[final + j])
        {
            new_array[i + j] = array1[start + i];
            i++;
        }
        else
        {
            new_array[i + j] = array1[final + j];
            answer += inversion - i;
            j++;
        }
    }
    
    while(start + i <= middle)
    {
        new_array[i + j] = array1[start + i];
        i++;
    }

    while(final + j <= last)
    {
        new_array[i + j] = array1[final + j];
        j++;
    }

    for (i = 0; i < last - start + 1; i++)
    {
        array1[start + i] = new_array[i];
    }


}

void merge_sort(long first, long last)
{

    if (first < last)
    {
        long middle = (first + last) / 2;

        merge_sort(first, middle);
        merge_sort(middle + 1, last);
        merge(first, last);
    }
}


int main()
{
    ifstream fin("inversions.in");
    ofstream fout("inversions.out");
    fin >> n;



    for(int i = 0; i < n; i++)
    {
        fin >> array1[i];
    }

    merge_sort(0, n - 1);

    fout << answer;


    fin.close();
    fout.close();
    return 0;
}