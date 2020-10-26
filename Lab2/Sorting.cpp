#include <iostream>
#include <fstream>
using namespace std;
void merge(long *array, int first, int last)
{
    int middle, start, final, j = 0, i = 0;
    long new_array[300000];


    middle = (first + last) / 2;
    start = first;
    final = middle + 1;


    while(start + i <= middle && final + j <= last)
    {
        if(array[start + i] <= array[final + j])
        {
            new_array[i + j] = array[start + i];
            i++;
        }
        else
        {
            new_array[i + j] = array[final + j];
            j++;

        }
    }
    while(start + i <= middle)
    {
        new_array[i + j] = array[start + i];
        i++;


    }
    while(final + j <= last)
    {
        new_array[i + j] = array[final + j];
        j++;
    }

    for (j = 0; j <= last - start; j++)
    {
        array[start + j] = new_array[j];
    }


}

void merge_sort(long *array, int first, int last)
{

    if (first < last)
    {
        int middle = (first + last) / 2;
        merge_sort(array, first, middle);
        merge_sort(array, middle + 1, last);
        merge(array, first, last);
    }
}


int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    long arr[n];


    for(int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        fout << arr[i] << " ";


    fin.close();
    fout.close();
    return 0;
}