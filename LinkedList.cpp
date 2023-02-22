/*
p7.cpp
Tyler Fregoso
3/22/21
Description: Example of a Linked list
 */


#include <iostream>
using namespace std;

//Class for the individual links
class Link
{
public:
    int iData; //data inside link
    Link *pNext; //points to next link
    
    Link(int id)
    {
        iData = id; //data inside link
        pNext = NULL; //assume next link has no value
        //unless linked to another link
    }
    
    void displayLink()
    {
        cout << "{ " << iData << " }"; //displays data inside link
    }
};

//Class for list of links
class LinkList
{
private:
    Link *pFirst; //points to first link
    
public:
    LinkList()
    {
        pFirst = NULL; //no links yet
    }
    
    bool isEmpty()
    {
        return pFirst == NULL; //true if the first link is NULL(empty)
    }
    
    void insertFirst(int id) //inserts int data into link
    {
        Link *pNewLink = new Link(id); //new link
        pNewLink->pNext = pFirst; //newlink -> old first
        pFirst = pNewLink; //first ->new link
    }
    
    Link *getFirst () {return pFirst;} //returns first link
    
    void removeFirst()
    {
        Link *pTemp = pFirst; //stores first as temp
        pFirst = pFirst->pNext; //first -> old link
        delete pTemp; // delete old first
    }
    
    void displayList() //displays full list
    {
        cout << "List (first --> last): ";
        Link *pCurrent = pFirst; //starts at beginning
        while (pCurrent != NULL) //loop runs until end (last link is NULL)
        {
            pCurrent->displayLink(); //display data inside each link
            pCurrent = pCurrent->pNext; //move to next link
        }
        cout <<endl;
    }
    
    Link *find(int key) //finds link with specific key
    {
        Link *pCurrent = pFirst; //start at first
        while (pCurrent->iData != key) //runs loop until link and key match
        {
            if (pCurrent->pNext == NULL) //if key isnt found return NULL
                return  NULL;
            else
                pCurrent = pCurrent->pNext;
        }
        return pCurrent;
    }
    
    bool remove (int key) //removes link with specified key
    {
        Link *pCurrent = pFirst; //start at beginning
        Link *pPrevious = pFirst;
        while(pCurrent->iData != key) //runs loop until link and key match
        {
            if (pCurrent->pNext == NULL)
                return false; //return false if key isnt found
            else
            {
                pPrevious = pCurrent; //searches next link
                pCurrent = pCurrent->pNext;
            }
        }
        
       //key is found
        if (pCurrent == pFirst)  //if its first link, change first
            pFirst = pFirst->pNext;
        else
            pPrevious->pNext = pCurrent->pNext; //bypass other links
        
        delete pCurrent; //deletes link
        
        return true;
    }
    
    int sumIData()
    {
        int sum = 0; //initialize sum as 0
        Link *pCurrent = pFirst; //start at beginning
        while (pCurrent != NULL) //goes through list
        {
            sum = sum + pCurrent->iData; //sum = sum + data in current link
            pCurrent = pCurrent->pNext; //move to next link
        }
        return sum;
    }
    
    int min()
    {
        Link *pCurrent = pFirst; //starts at beginning
        int min = pFirst->iData; //initializes min as data in first link
        while (pCurrent != NULL) //searches links
        {
            if (pCurrent->iData < min) // if data in current link is less than min
                min = pCurrent->iData; //min is the current link
            pCurrent = pCurrent->pNext; //moves through next link
        }
        return min;
    }
    
    int numLinks()
    {
        int counter = 0; //counts how many links
        Link *pCurrent = pFirst; //starts at beginning
        while (pCurrent != NULL) //searches through list
        {
            counter ++; //adds 1 to counter
            pCurrent = pCurrent->pNext; //keeps loop going until end is found
        }
        return counter;
    }
    
};

int main()
{
    LinkList theList;
    theList.insertFirst(22);
    theList.insertFirst(44);
    theList.insertFirst(66);
    theList.insertFirst(88);
    
    theList.displayList();
    
    while (!theList.isEmpty() )
    {
        Link *pTemp = theList.getFirst();
        cout << "\nRemoving link with data ";
        pTemp->displayLink();
        theList.removeFirst();
    }
    cout << endl << "Empty list : ";
    theList.displayList();
    
    theList.insertFirst(22);
    theList.insertFirst(44);
    theList.insertFirst(66);
    theList.insertFirst(88);
    cout << "\nReinserting the links back" << endl;
    theList.displayList();
    
    int findKey = 44;
    Link *pFind = theList.find(findKey);
    if(pFind != NULL)
        cout << "Found link with key: "<<pFind->iData <<endl;
    else
        cout << "Can't find link with key " <<findKey<<endl;
    
    if (theList.remove(findKey))
        cout << "Deleted " <<findKey<<" from the list.\n";
    else
        cout << "Did not delete " <<findKey<<" from the list.\n";
    
    cout << "Link list after deletion\n";
    theList.displayList();
    cout <<"The sum of the links is: " << theList.sumIData()<<endl;
    cout << "The smallest link is: " <<theList.min()<<endl;
    cout <<"The number of links is: " << theList.numLinks()<<endl;
}

/*===OUTPUT===
 List (first --> last): { 88 }{ 66 }{ 44 }{ 22 }

 Removing link with data { 88 }
 Removing link with data { 66 }
 Removing link with data { 44 }
 Removing link with data { 22 }
 Empty list : List (first --> last):

 Reinserting the links back
 List (first --> last): { 88 }{ 66 }{ 44 }{ 22 }
 Found link with key: 44
 Deleted 44 from the list.
 Link list after deletion
 List (first --> last): { 88 }{ 66 }{ 22 }
 The sum of the links is: 176
 The smallest link is: 22
 The number of links is: 3
 */
