#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct country_name
{
    string country;
    string name;
};

country_name array1[100000], new_array[100000];

void merge(long first, long last)
{
    long middle, start, final, j = 0, i = 0;


    middle = (first + last) / 2;
    start = first;
    final = middle + 1;

    while(start + i <= middle && final + j <= last)
    {
        if(array1[start + i].country <= array1[final + j].country)
        {
            new_array[i + j] = array1[start + i];
            i++;
        }
        else
        {
            new_array[i + j] = array1[final + j];
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
    ifstream fin("race.in");
    ofstream fout("race.out");

    int n;
    string count;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> array1[i].country >> array1[i].name;

    }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (count != array1[i].country)
        {
            fout << "=== " << array1[i].country << " ===" << "\n";
            count = array1[i].country;
        }
        fout << array1[i].name << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}