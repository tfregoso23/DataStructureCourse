/*
p9.cpp
Tyler Fregoso
4/5/21
Description: Double Linked, Double Ended, Priority Queue List
 */

#include <iostream> //allows setw
#include <iomanip>
using namespace std;


class Link
{
public:
    int data;
    Link *pNext, *pPrev;
    Link (int newData) {data = newData; pNext = NULL; pPrev = NULL;}
    void display()
    {
        cout << " { " << setw(3) << data << "\t:\t"
        << setw(14) <<pPrev<<"\t:\t\t" << &data
        << "\t:\t" <<setw(14)<<pNext << " }\n";
    }
};

class DoubleEndedList
{
private:
    Link *pFirst, *pLast;
    
public:
    DoubleEndedList()   {pFirst=NULL; pLast=NULL;}
    void displayFirst() {cout << "First: "; pFirst->display(); }
    void displayLast()  {cout << "Last: "; pLast->display();}
    void displayList()
    {
        Link *Current = pFirst;
        cout <<" Begin List: \n";
        cout << "{ data\t:\t\t\tpPrev\t\t\tself\t\t\t\tpNext\t\t}\n";
        while(Current!=NULL) //display list until reaches last link (NULL)
        {
            Current->display();
            Current = Current->pNext;
        }
    }
    
    void displayBackward()
    {
        Link *Current = pLast; //start from last
        cout << "{ data\t:\t\t\tpPrev\t\t\tself\t\t\t\tpNext\t\t}\n";
        while (Current!=NULL)
        {
            Current->display();
            Current = Current->pPrev; //display previous until first link (NULL)
        }
    }
    
    void insert(int newValue)
    {
        Link *newLink = new Link(newValue);
        
        if (pFirst == NULL) //If no links
        {
            cout << "Inserting the first/last link: \n";
            newLink->display();
            cout <<endl;
            newLink->pNext=NULL;
            newLink->pPrev = NULL;
            pFirst = newLink;
            pLast = newLink;
            return;
        }
        
        if (newValue < pFirst->data) //new value is less than first
        {
            cout << "Inserting new First Link: \n";
            newLink->display();
            cout <<endl;
            pFirst->pPrev = newLink; //New link is previous to prior first
            newLink->pPrev = NULL; //Prev new link is NULL
            newLink->pNext = pFirst; //Next link after newlink is prior first
            pFirst = newLink; //first is now new link
            return;
        }
        
        if (newValue > pLast->data) //New value is more than last
        {
            cout << "Inserting new Last Link: \n";
            newLink->display();
            cout <<endl;
            pLast->pNext = newLink; //new link goes after last
            newLink->pPrev = pLast; //Prev new link is prior last
            newLink->pNext = NULL; //New link next is NULL
            pLast = newLink; //New link is now last
            return;
        }
        
        cout << "Inserting new Link in middle: ";
        newLink->display();
        Link *Next = pFirst; //start at first link
        while(Next != NULL) //search all links
        {
            if (newValue < Next->data) //new value is less than data of next
                break;
            Next = Next->pNext;
        }
        newLink->pNext = Next; //new link next is wherever loop stopped
        newLink->pPrev = Next->pPrev; // previous of new link is old links previous
        Next->pPrev->pNext = newLink; //old links previous' next is now new link
        Next->pPrev = newLink;
    }
    
    void removeFirst()
    {
        cout << "Removing first link: " <<endl;
        Link *Delete;
        Delete = pFirst; //delete = firstlink
        pFirst = pFirst->pNext; //the prior second link is now first
        pFirst->pPrev = NULL;
        delete Delete;
    }
    
    void removeLast()
    {
        cout << "Removing last link: " <<endl;
        Link *Delete;
        Delete = pLast;
        pLast = pLast->pPrev; //the second to last link is now last
        pLast->pNext = NULL;
        delete Delete;
    }
    
    void removeValue(int value)
    {
        if (pFirst->data == value)
        {
        removeFirst();
            return;
        }
        else if (pLast->data == value)
        {
            removeLast();
            return;
        }
        Link *Delete = pFirst;
        while(Delete!=NULL)
        {
            if (Delete->data == value)
            {
                cout << "Deleting in middle: \n";
                Delete->display();
                Delete->pNext->pPrev = Delete->pPrev;
                Delete->pPrev->pNext = Delete->pNext;
                delete Delete;
                return;
            }
            Delete = Delete->pNext;
        }
        cout << "Could not find link with " << value <<endl;
    }
};

int main()
{
    DoubleEndedList *aList = new DoubleEndedList();
    aList->insert(10);
    aList->displayList();
    aList->insert(5);
    aList->displayList();
    aList->insert(4);
    aList->displayList();
    aList->insert(20);
    aList->displayList();
    aList->insert(21);
    aList->displayList();
    aList->insert(3);
    aList->displayList();
    aList->insert(6);
    aList->displayList();
    
    aList->insert(24);
    aList->displayList();
    aList->insert(22);
    aList->displayList();
    aList->insert(23);
    aList->displayList();
    aList->insert(1);
    aList->displayList();
    cout << "The list from beginning to end\n";
    aList->displayList();
    cout << "The list backward\n";
    aList->displayBackward();
    aList->removeFirst();
    aList->displayList();
    aList->removeLast();
    aList->displayList();
    aList->removeValue(3);
    aList->displayList();
    aList->removeValue(23);
    aList->displayList();
    aList->removeValue(21);
    aList->displayList();
    aList->insert(8);
    aList->displayList();
}

/*===OUTPUT===
 Inserting the first/last link:
  {  10    :               0x0    :        0x1005c2100    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {  10    :               0x0    :        0x1005c2100    :               0x0 }
 Inserting new First Link:
  {   5    :               0x0    :        0x1005c2120    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   5    :               0x0    :        0x1005c2120    :       0x1005c2100 }
  {  10    :       0x1005c2120    :        0x1005c2100    :               0x0 }
 Inserting new First Link:
  {   4    :               0x0    :        0x1005c2140    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x1005c2100 }
  {  10    :       0x1005c2120    :        0x1005c2100    :               0x0 }
 Inserting new Last Link:
  {  20    :               0x0    :        0x1005c2160    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x1005c2100 }
  {  10    :       0x1005c2120    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :               0x0 }
 Inserting new Last Link:
  {  21    :               0x0    :        0x103804140    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x1005c2100 }
  {  10    :       0x1005c2120    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :               0x0 }
 Inserting new First Link:
  {   3    :               0x0    :        0x103804160    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x1005c2100 }
  {  10    :       0x1005c2120    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :               0x0 }
 Inserting new Link in middle:  {   6    :               0x0    :        0x103804180    :               0x0 }
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :               0x0 }
 Inserting new Last Link:
  {  24    :               0x0    :        0x1005c2180    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x1005c2180 }
  {  24    :       0x103804140    :        0x1005c2180    :               0x0 }
 Inserting new Link in middle:  {  22    :               0x0    :        0x100704d50    :               0x0 }
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x1005c2180 }
  {  24    :       0x100704d50    :        0x1005c2180    :               0x0 }
 Inserting new Link in middle:  {  23    :               0x0    :        0x100704d70    :               0x0 }
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  23    :       0x100704d50    :        0x100704d70    :       0x1005c2180 }
  {  24    :       0x100704d70    :        0x1005c2180    :               0x0 }
 Inserting new First Link:
  {   1    :               0x0    :        0x100704d90    :               0x0 }

  Begin List:
 { data    :            pPrev            self                pNext        }
  {   1    :               0x0    :        0x100704d90    :       0x103804160 }
  {   3    :       0x100704d90    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  23    :       0x100704d50    :        0x100704d70    :       0x1005c2180 }
  {  24    :       0x100704d70    :        0x1005c2180    :               0x0 }
 The list from beginning to end
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   1    :               0x0    :        0x100704d90    :       0x103804160 }
  {   3    :       0x100704d90    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  23    :       0x100704d50    :        0x100704d70    :       0x1005c2180 }
  {  24    :       0x100704d70    :        0x1005c2180    :               0x0 }
 The list backward
 { data    :            pPrev            self                pNext        }
  {  24    :       0x100704d70    :        0x1005c2180    :               0x0 }
  {  23    :       0x100704d50    :        0x100704d70    :       0x1005c2180 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   3    :       0x100704d90    :        0x103804160    :       0x1005c2140 }
  {   1    :               0x0    :        0x100704d90    :       0x103804160 }
 Removing first link:
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  23    :       0x100704d50    :        0x100704d70    :       0x1005c2180 }
  {  24    :       0x100704d70    :        0x1005c2180    :               0x0 }
 Removing last link:
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   3    :               0x0    :        0x103804160    :       0x1005c2140 }
  {   4    :       0x103804160    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  23    :       0x100704d50    :        0x100704d70    :               0x0 }
 Removing first link:
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :       0x100704d70 }
  {  23    :       0x100704d50    :        0x100704d70    :               0x0 }
 Removing last link:
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x103804140 }
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  {  22    :       0x103804140    :        0x100704d50    :               0x0 }
 Deleting in middle:
  {  21    :       0x1005c2160    :        0x103804140    :       0x100704d50 }
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x1005c2100 }
  {  10    :       0x103804180    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x100704d50 }
  {  22    :       0x1005c2160    :        0x100704d50    :               0x0 }
 Inserting new Link in middle:  {   8    :               0x0    :        0x103804140    :               0x0 }
  Begin List:
 { data    :            pPrev            self                pNext        }
  {   4    :               0x0    :        0x1005c2140    :       0x1005c2120 }
  {   5    :       0x1005c2140    :        0x1005c2120    :       0x103804180 }
  {   6    :       0x1005c2120    :        0x103804180    :       0x103804140 }
  {   8    :       0x103804180    :        0x103804140    :       0x1005c2100 }
  {  10    :       0x103804140    :        0x1005c2100    :       0x1005c2160 }
  {  20    :       0x1005c2100    :        0x1005c2160    :       0x100704d50 }
  {  22    :       0x1005c2160    :        0x100704d50    :               0x0 }
 */
