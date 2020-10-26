#include <fstream>
#include<iostream>


using namespace std;

int main()
{
   ifstream fin("brackets.in");
   ofstream fout("brackets.out");
   string brackets[500];

   char stack_array[10000], symbol;
   int index, len, i = -1;


   while((fin >> brackets[++i]) && (brackets[i] != "") )
   {

       index = -1;
       len = brackets[i].length();

       for (int j = 0; j < len; j++)
       {
           symbol = brackets[i][j];

           if(symbol == '[' || symbol == '(')
               stack_array[++index] = symbol;

           else if(symbol == ']')
           {
               if(stack_array[index] == '[')
                   index--;
               else
               {
                   index = 1;
                   break;
               }
           }
           else if(symbol == ')')
           {
               if(stack_array[index]  == '(')
                   index--;
               else
               {
                   index = 1;
                   break;
               }
           }
       }

       if(index == -1)
           fout << "YES" << "\n";
       else
           fout << "NO" << "\n";
   }
   fin.close();
   fout.close();
   return 0;
}