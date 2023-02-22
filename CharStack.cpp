/*
p6.cpp
Tyler Fregoso
3/13/21
Description: Example of a character stack class
 */

#include <iostream>
using namespace std;

class CharStack
{
private:
    int size; //size of stack
    int top;  // top of stack
    char *stackArray; //dynamic array
    
public:
    CharStack(int newSize) //constructor
    {
        size = newSize; // size of stack
        stackArray = new char[size]; //creates array with designated size
        top = -1; //sets the top to -1 (no items yet)
    }
    
    void push(char newValue) { stackArray[++top] = newValue;} //inserts character and increments top
    
    char pop() {return stackArray[top--];} //decrements top
    
    char peek() {return stackArray[top];} //shows whats on top of stack
    
    bool isEmpty() {return (top == -1); } //checks if array is empty
    
    bool isFull() { return (top == size -1); } //checks if array is full
        
    
};

int main()
{
    CharStack charArray(12);
    
    //pushin characters
    charArray.push('h');
    charArray.push('e');
    charArray.push('l');
    charArray.push('l');
    charArray.push('o');
    charArray.push(' ');
    charArray.push('w');
    charArray.push('o');
    charArray.push('r');
    charArray.push('l');
    charArray.push('d');
    charArray.push('!');
    
    while (!charArray.isEmpty()) //cout chars until array is empty
    {
        cout << charArray.pop();
    }
    cout <<endl;
}

/* ===OUTPUT===
 !dlrow olleh
 */
