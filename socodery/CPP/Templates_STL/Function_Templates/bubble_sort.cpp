#include<iostream>
using namespace std;

template <typename X>
void bubble(X *array, int array_size)
{
    X temp_var;
    int counter_1, counter_2;

    for ( counter_1 = 0; counter_1 < array_size; counter_1++)
        {
         for(counter_2 = 1; counter_2 <(array_size-counter_1); counter_2++)
          {

             if (array[counter_2] < array[counter_2 - 1])
             {
                    temp_var = array[counter_2];
                    array[counter_2] = array[counter_2 - 1];
                    array[counter_2 - 1] = temp_var;
             }
           }
         }
}

int main()
{
    int int_array[5]= {4,5,1,3,2};
    double double_array[5] = {2.6,1.1,3.1,4.5};
    
    cout << "Unsorted int array is \n";
    for(int i=0;i <5;i++)
        cout << int_array[i] << "\n";
    
    bubble(int_array,5);
    
    cout << "\nSorted int array is \n";
    for(int i=0;i <5;i++)
        cout << int_array[i] << "\n";
    
    cout << "\nUnsorted double array is \n";
    for(int i=0;i <4;i++)
        cout << double_array[i] << "\n";
    
    bubble(double_array,4);

    cout << "\nSorted double array is \n";
    for(int i=0;i <4;i++)
        cout << double_array[i] << "\n";
    return 0;
}
