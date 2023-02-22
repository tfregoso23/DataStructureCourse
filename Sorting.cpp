/*
p5.cpp
Tyler Fregoso
3/8/21
Description: Array Encapsulation with sorting functions
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
        void swap(int index1, int index2)
        {
            //Used for sorts; Swaps indexes
            int temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
        }
        
        void bubbleSort()
        {
            for (int i = 0; i < number_of_elements-1; i++)
                     for (int j = 0; j < number_of_elements-(i+1); j++)
                         if (array[j] > array[j+1])
                             swap(j,j+1);
        }
    
        void selectSort()
        {
            int min, min_index;
            for (int current_index=0; current_index < number_of_elements-1;current_index++)
            {   //Loops through every index of array^
                min_index = current_index;
                for(int i = current_index+1; i < number_of_elements; i++)
                    if (array[i] < array[min_index])
                        //Grabs the last index from loop above and compares it to the
                        // next index, sorts based on which is smaller
                        min_index = i;
                
                swap(current_index, min_index);
            }
        }
    
        void insertSort()
        {
            int in, out, temp;
            for(out = 1; out < number_of_elements; out++)
            {
                //Int in loops with int out
                in = out;
                temp = array[in]; //stores array[in] as current temp
                while (in > 0 && array[in-1] > temp)
                    //whole loop goes on until you reach farthest left
                    //or find a number < temp
                {
                    array[in] = array[in-1];
                    in--;
                }
                array[in] = temp;
            }
        }
    
    void deleteIndex(int index_to_delete)
        {
            //shifts all elemts above index left one
            for (int i = index_to_delete; i <= number_of_elements-2;i++)
                array[i] = array [i+1];
            number_of_elements--;
            //Decreases number of elements after loop
        }
    
    void noDups()
        {
            //assumes array is sorted
            //runs a loop that compares index next to eachother
            for (int i = 0; i < number_of_elements-1; i++)
            {
                if (array[i] == array[i+1])
                {
                    //if indexes are the same, call function to delete tht index
                    deleteIndex(i+1);
                    i--;
                }
            }
        }
    
    void insert_in_order(int number_to_insert)
    {
        int index_insert;
        //Loops through each index in array
        //If the index of the array is higher than the number you
        // want to insert, break loop
        for(index_insert = 0; index_insert < number_of_elements; index_insert++)
            if (array[index_insert] > number_to_insert)
                break;
        
        //shifts units
        for (int i = number_of_elements-1; i>= index_insert; i--)
            array[i+1] = array[i]; //shifts units above index right one
        array[index_insert] = number_to_insert;
        number_of_elements++; //increases number of elements
            

    }
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
    anArray.add(101);
    anArray.add(9);
    anArray.show();
    anArray.add(99);
    anArray.show();
    anArray.bubbleSort();
    anArray.show();
    anArray.insertFirst(33);
    anArray.show();
    anArray.selectSort();
    anArray.show();
    anArray.insertFirst(300);
    anArray.show();
    anArray.insertSort();
    anArray.show();
    anArray.deleteIndex(2);
    anArray.show();
    anArray.deleteIndex(2);
    anArray.show();
    anArray.deleteIndex(2);
    anArray.show();
    anArray.insert_in_order(10);
    anArray.insert_in_order(10);
    anArray.insert_in_order(10);
    anArray.show();
    anArray.noDups();
    anArray.show();
}

/*===OUTPUT===
 array = {101, 9}
 array = {101, 9, 99}
 array = {9, 99, 101}
 array = {33, 9, 99, 101}
 array = {9, 33, 99, 101}
 array = {300, 9, 33, 99, 101}
 array = {9, 33, 99, 101, 300}
 array = {9, 33, 101, 300}
 array = {9, 33, 300}
 array = {9, 33}
 array = {9, 10, 10, 10, 33}
 array = {9, 10, 33}
 */

