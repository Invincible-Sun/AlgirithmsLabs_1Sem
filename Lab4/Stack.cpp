#include <fstream>
#include<iostream>
using namespace std;

int main()
{
   ifstream fin("stack.in");
   ofstream fout("stack.out");

   long stack_array[1000000], addition;
   char command;
   int number_of_commands, index = 0;

   fin >> number_of_commands;
   for(int i = 0; i < number_of_commands; i++)
   {

       fin >> command;
       if(command == '+' )
       {
           fin >> addition;
           stack_array[index] = addition;
           index++;
       }
       else
           fout << stack_array[--index] << "\n";
   }

   fin.close();
   fout.close();
    return 0;
}