#include <fstream>
#include<iostream>
long size_of_array;
using namespace std;
long bin_search(long array[], long key)
{
    long left = - 1;
    long right = size_of_array, middle;
    while(right > left + 1)
     {
        middle = (left + right) / 2;
        if (array[middle] < key)
            left = middle;
        else
            right = middle;
    }
    if(right < size_of_array && array[right] == key)
        return right + 1;
    else
        return -1;

}
long reverse_bin_searsh(long array[], long key, long first_index)
{
    for(int i = first_index + 1; i < size_of_array; i++)
    {
        if(array[size_of_array - 1] == array[first_index])
            return size_of_array;
        if(array[first_index] < array[i])
            return i;
    }
    return -1;
}

int main()
{
   ifstream fin("binsearch.in");
   ofstream fout("binsearch.out");
   int requests;
   fin >> size_of_array;
   long array[size_of_array], start_ind;

   for(int i = 0; i < size_of_array; i++)
        fin >> array[i];

   fin >> requests;
   long requests_array[requests];

   for(int i = 0; i < requests; i++)
        fin >> requests_array[i];

   for(int i = 0; i < requests; i++)
   {
       start_ind = bin_search(array, requests_array[i]);
       if(start_ind != -1)
           fout << start_ind << " " << reverse_bin_searsh(array,requests_array[i], start_ind - 1);

       else
           fout << -1 << " " << -1;

       fout << "\n";


   }

   fin.close();
   fout.close();
   return 0;
}