#include <fstream>
#include<iostream>
using namespace std;
int left_index, right_index;
void splitting(int array[], int start, int end)
{

    if(array[start] > array[end])
        swap(array[start], array[end]);

    if(array[start + 1] > array[end])
        swap(array[start + 1], array[end]);

    if(array[start] > array[start + 1])
        swap(array[start], array[start + 1]);

    int base = array[start + 1];
    left_index = start + 1;
    right_index = end;

    while(left_index <= right_index)
    {
        while(array[++left_index] < base);
        while(array[--right_index] > base);
        if(left_index > right_index)
            break;
        swap(array[left_index], array[right_index]);
    }
    swap(array[right_index], array[start + 1]);
}


int finding_kth(int array[], int start, int end, int k)
{
    while(start <= end)
    {
        if (end <= start + 1)
        {
            if (end == start + 1 && array[end] < array[start])
                swap (array[start], array[end]);
            return array[k];
        }
        splitting(array, start, end);

        if(right_index >= k)
            end = right_index - 1;
        if(left_index <= k)
            start = left_index;
    }
}


int main()
{
    fstream fin("kth.in");
    ofstream fout("kth.out");
    int k, n;
    fin >> n >> k;
    int array[n];
    int  a, b, c;
    fin >> a >> b >> c >> array[0] >> array[1];

    for(int i = 2; i < n; i++)
    {
        array[i] = a * array[i - 2] + b * array[i - 1] + c;
    }


    fout << finding_kth(array, 0, n - 1, k - 1);

    fin.close();
    fout.close();

    return 0;
}