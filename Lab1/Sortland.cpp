#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
  long n;
  float b;
  

  ifstream fin ("sortland.in");
  ofstream fout ("sortland.out");
  fin >> n ;

  int follow[n];
  for(int i = 0; i < n; i++)
  {
      follow[i] = i;
  }

  float wealth[n];
  for(int i = 0; i < n; i++){
      fin >> wealth[i];
  }
  
  for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i < j && wealth[i] > wealth[j])
            {
                b = wealth[i];
                wealth[i] = wealth[j];
                wealth[j] = b;

                b = follow[i];
                follow[i] = follow[j];
                follow[j] = b;
            }
        }
    }
fout << follow[0] + 1 << " " << follow[n / 2] + 1 << " " << follow[n-1] + 1;

  fin.close ();
  fout.close ();
  return 0;
}