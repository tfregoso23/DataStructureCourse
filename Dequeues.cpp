/*
p6.cpp
Tyler Fregoso
3/15/21
Description: Implements a double ended queue (dequeue)
 */

#include <iostream>
using namespace std;

class Queue
{
private:
    int size, front, rear, number_items;
    int *queueArray; //dynamic array
    
public:
    Queue(int newSize) //constructor
    {
        size = newSize; //size is equal to whats entered
        queueArray = new int[size]; //makes an array of entered size
        front = 0; //nothing here yet
        rear = -1;
    }
    
    //Inserts to the right (like normal)
    void insertRight(int newValue)
    {
        //Wrap around :
        // if rear is set to end of array, wrap it back around to -1
        if (rear == size-1)
            rear = -1;
        
        rear++; //Increment rear by 1
        queueArray[rear] = newValue; //sets the rear as value entered
        number_items++; //increases number of items
    }
    
    //Inserts from left of array
    void insertLeft(int newValue)
    {
        //Wrap around:
        //if front is first index of array, move to far right
        if (front == 0)
            front = size;
        
        front--; //front decreases by one
        queueArray[front] = newValue; //value entered on left is new front
        number_items++; //increases number of items
    }
    
    int removeLeft()
    {
        int temp = queueArray[front++]; //sets temp
        if (front == size) //if front is to the rear
            front = 0;     //make front the far left
        
        number_items--; //decreases number of items
        return temp;
    }
    
    void removeRight()
    {
        //Wrap around:
        //if rear is far left, bring rear to the far right
        if (rear == 0)
            rear = size;
        
        rear--; //decreases rear by one
        number_items--; //decreases number of itemd
    }
    
    int peekFront() {return queueArray[front];      }
    int peekRear()  {return queueArray[rear];       }
    bool isEmpty()  {return (number_items == 0);    }
    bool isFull()   {return (number_items == size); }
    bool qsize()    {return number_items;           }
};

int main()
{
    Queue testQueue(5);
    testQueue.insertRight(10);
    testQueue.insertRight(20);
    testQueue.insertRight(30);
    testQueue.insertRight(40);
    
    while (!testQueue.isEmpty())
    {
        cout << testQueue.peekRear() << " ";
        testQueue.removeRight();
    }
    cout <<endl;
    
    testQueue.insertRight(10);
    cout << "\n" << testQueue.peekRear() << " ";
    cout << "\n" <<testQueue.peekFront() << " ";
    testQueue.insertLeft(20);
    cout << "\n" <<testQueue.peekFront() << " ";
    testQueue.insertLeft(30);
    cout << "\n" <<testQueue.peekFront() << " ";
    testQueue.removeLeft();
    cout << "\n" <<testQueue.peekFront() << " ";
}

/*===OUTPUT===
 40 30 20 10

 10
 10
 20
 30
 20
 */
