#include <fstream>
#include <iostream>
using namespace std;
long size1 = 0;

long array1[1000000];
long push_commands[1000000];


void sift_up(int i)
{
    if(i != 0)
    {
        if(array1[i] < array1[(i - 1) / 2])
        {
            swap(array1[i], array1[(i - 1) / 2] );
            swap(push_commands[i], push_commands[(i - 1) / 2]);
            sift_up((i - 1 ) / 2);
        }
    }
}
void sift_down(int root)
{
    int left_child, right_child, smallest;
    left_child = 2 * root + 1;
    right_child = 2 * root + 2;
    smallest = root;

    if (left_child < size1  && array1[root] > array1[left_child])
        smallest = left_child;

    if (right_child < size1 && array1[smallest] > array1[right_child])
        smallest = right_child;

    if (smallest != root)
    {
        swap(array1[root], array1[smallest]);
        swap(push_commands[root], push_commands[smallest]);
        sift_down(smallest);
    }

}
int finding(int to_find)
{
    for(int i = 0; i < size1; i++)
    {
        if(push_commands[i] == to_find )
            return i;
    }
}


int main()
{
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
    string command;
    int index = 0;
    while(fin >> command)
    {
        index++;
        if(command.length() == 0)
            break;
        if(command == "push")
        {
            long element;
            fin >> element;
            size1++;
            array1[size1 - 1] = element;
            push_commands[size1 - 1] = index;
            sift_up(size1 - 1);

        }
        else if(command == "extract-min")
        {
            if(size1 == 0)
                fout << "*\n";
            else
            {
                fout << array1[0] << "\n";
                swap(array1[0], array1[size1 - 1]);
                swap(push_commands[0], push_commands[size1 - 1]);
                size1--;
                sift_down(0);
            }
        }
        else if(command == "decrease-key")
        {
            int number_of_str, element_for_change;
            fin >> number_of_str >> element_for_change;

            int found_element = finding(number_of_str);
            array1[found_element] = element_for_change;

            if(found_element != 0 && array1[found_element] < array1[(found_element - 1) / 2])
                sift_up(found_element);
            else
                sift_down(found_element);
        }
        


    }
    fin.close();
    fout.close();

}