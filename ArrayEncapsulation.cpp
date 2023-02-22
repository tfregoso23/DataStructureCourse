/*
p3.cpp
Tyler Fregoso
2/18/21
Description: Type up sample Array encapsulation program and add the various functions
 */

#include <iostream>
using namespace std;

class EncapsulatedArray
{
    private:
        int *array;
        int number_of_elements;
    public:
        EncapsulatedArray(int size);
        void add(int number_to_add);
        void show();
        void insertFirst(int number_to_add);
        void deleteNumber(int number_to_delete);
        void sort();
};

EncapsulatedArray :: EncapsulatedArray(int size)
{
    array = new int[size]; //Dynamically allocated array
    number_of_elements = 0;
}

void EncapsulatedArray:: add(int number_to_add)
{
    array[number_of_elements] = number_to_add;
    number_of_elements++;
}

//Shows array
void EncapsulatedArray::show()
{
    if (number_of_elements == 1)
    {
        cout << "array = {" << array[0] << "} \n";
        return;
    }
    int i;
    cout << "array = {";
    for (i = 0; i < number_of_elements-1; i++)
        cout << array[i] << ", ";
    cout << array[i] << "}" <<endl;
        
}

void EncapsulatedArray::insertFirst(int number_to_add)
{
    int i;
    //shifts array to right by 1, and leaves array[0] empty
    for (i=number_of_elements-1; i>=0; i--)
        array[i+1] = array[i];
    array[0] = number_to_add; // This replaces the empty array[0] with number
    number_of_elements++; //Increases elements shown
}

void EncapsulatedArray::deleteNumber(int number_to_delete)
{
    int numDelete; //finds the number to delete
    for (numDelete=0; numDelete < number_of_elements-1; numDelete++)
        if (array[numDelete] == number_to_delete) //if array finds number stop loop
            break;
    if (numDelete == number_of_elements-1) //if number isnt found return
        return;
    int i;
    for (i=numDelete; i <number_of_elements; i++) // shifts units left after number is deleted
        array[i] = array[i+1];
    number_of_elements--; //resize
}

void EncapsulatedArray::sort()
{
    //bubble sort
    int temp;
    int i;
    cout << "array = {";
     for (i=number_of_elements-1; i>0; i--)
         {
                for (int j =0; j < i; j++)
                {
                    
                    if ( array[j] > array [j+1] )
                    {
                        
                        temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
               
                }

         }
    for (i=0; i < number_of_elements-1; i++)
          cout << array[i] << ",";
      cout << array[i] << "}" <<endl;
}

int main()
{
    EncapsulatedArray anArray(5);
    anArray.add(9);
    anArray.show();
    anArray.add(101);
    anArray.add(9);
    anArray.show();
    anArray.insertFirst(14);
    anArray.show();
    anArray.deleteNumber(101);
    anArray.show();
    anArray.sort();
}

/*===OUTPUT===
 array = {9}
 array = {9, 101, 9}
 array = {14, 9, 101, 9}
 array = {14, 9, 9}
 array = {9,9,14}
 */
