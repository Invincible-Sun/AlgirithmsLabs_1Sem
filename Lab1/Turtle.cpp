#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("turtle.in");
    ofstream fout ("turtle.out");

    int h, w;
    fin >> h >> w;
    int arr[h][w];

    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = 0; j < w; j++)
        {
            fin >> arr[i][j];
        }
    }

    for (int i = 1; i < h; i++)
    {
        arr[i][0] += arr[i - 1][0];
    }

    for (int i = 1; i < w; i++)
    {
        arr[0][i] += arr[0][i - 1];
    }

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
        }
    }

    fout << arr[h -1][w - 1];

    fin.close();
    fout.close();
    return 0;
}
