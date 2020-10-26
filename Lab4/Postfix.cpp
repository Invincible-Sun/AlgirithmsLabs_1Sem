#include <fstream>
#include<iostream>


using namespace std;

int main()
{
   ifstream fin("postfix.in");
   ofstream fout("postfix.out");

   int stack_array[200];
   long long stack_iter = -1;
   char symbol;


   while(fin >> symbol)
   {

       if((int)symbol >= 48 && (int)symbol <= 57)
       {
           int i_symbol = (int)symbol - 48;
           stack_array[++stack_iter] = i_symbol;
           continue;
       }
       else
       {

           switch(symbol)
           {
               case '+':
                   stack_array[stack_iter - 1] += stack_array[stack_iter];
                   break;
               case '-':
                   stack_array[stack_iter - 1] = stack_array[stack_iter- 1] - stack_array[stack_iter];
                   break;
               case '*':
                   stack_array[stack_iter - 1] *= stack_array[stack_iter];
                   break;
           }

           stack_iter--;
       }
   }

   fout << stack_array[0];
   fin.close();
   fout.close();
   return 0;
}