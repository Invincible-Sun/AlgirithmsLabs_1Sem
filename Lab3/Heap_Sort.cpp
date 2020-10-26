#include <iostream>
#include <fstream>
using namespace std;

void sift_down(long array[], long size, long root)
{
    long left_child, right_child, largest;
    left_child = 2 * root + 1;
    right_child = 2 * root + 2;
    largest = root;

    if (left_child < size  && array[root] < array[left_child])
        largest = left_child;

    if (right_child < size && array[largest] < array[right_child])
        largest = right_child;

    if (largest != root)
    {
        swap(array[root], array[largest]);
        sift_down(array, size, largest);
    }

}
void heap_sort(long array[], long size)
{
    for(long i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i);

    for(long i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        sift_down(array, i, 0);
    }

}

int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    long n;
    fin >> n;
    long array[n];
    for(int i = 0; i < n; i++)
    {
        fin >> array[i];
    }

    heap_sort(array, n);
    for(int i = 0; i < n; i++)
    {
        fout << array[i] << " ";
    }
    fin.close();
    fout.close();

}