#include <fstream>
#include<iostream>
using namespace std;

int main()
{
   ifstream fin("queue.in");
   ofstream fout("queue.out");

   long queue_array[1000000], addition;
   char command;
   int number_of_commands, index = 0, tail = 0;

   fin >> number_of_commands;
   for(int i = 0; i < number_of_commands; i++)
   {

       fin >> command;
       if(command == '+' )
       {
           fin >> addition;
           queue_array[index] = addition;
           index++;
       }
       else
           fout << queue_array[tail++] << "\n";
   }

   fin.close();
   fout.close();
    return 0;
}