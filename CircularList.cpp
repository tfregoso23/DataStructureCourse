/*
p8.cpp
Tyler Fregoso
3/27/21
Description: Circular list
 */

#include <iostream>
using namespace std;

class Link
{
public:
    int data;
    Link *next;
    Link (int newData)  {data = newData; next = NULL;}
    void show()         {cout << "{" << data << "}" ;}
};

class CircularList
{
private:
    Link *current;
    int numLinks;
public:
    CircularList()      {current = NULL; numLinks = 0;}
    bool empty()        {return (numLinks == 0);      }
    
    //searches links for value
    bool search(int valueToFind)
    {
        //tests to see if list is empty
        if (!empty()) //if its not empty
            
            //Go through all links and retyrn true if value is found
            for (int i = 0; i < numLinks; i++)
            {
                if (current->data == valueToFind)
                    return true;
                current = current->next; //check nect link
            }
        return false;
    }
    
    //deletes link
    bool deleteLink(int valueToFind)
    {
        if (!empty())
            //Goes through all links
            for (int i = 0; i < numLinks; i++)
            {
                //If the data is the value entered
                if (current->next->data == valueToFind)
                {
                    Link *deleteThis = current->next; // deleteThis is link with value
                    current->next = deleteThis->next;
                    delete deleteThis; //delete the link
                    numLinks--; //subtracts number of links
                    return true;
                }
                current = current->next;
            }
        return false;
    }
    
    void displayList()
    {
        cout << "The list: ";
        if (!empty())
            //Goes through each link and shows
            for (int i = 0; i <numLinks; i++)
            {
                current->show();
                current=current->next;
            }
        else
            cout << "is empty\n";
    }
    
    void insertInitialLink(int newValue)
    {
        //first link inserted
        Link *newLink = new Link(newValue);
        current = newLink;
        current->next = newLink;
        numLinks++;
    }
    
    void insertAfterValueFound(int newValue, int valueToFind)
    {
        //searches for specific link value
        if ( search(valueToFind) )
        {
            //if link is found, make new link after it
            Link *newLink = new Link(newValue);
            newLink->next = current->next;
            current->next = newLink;
            numLinks++;
        }
        else
            cout << "Value " << valueToFind << " not found." <<endl;
    }
    
};

int main()
{
    CircularList circ;
    cout << boolalpha;
    cout << "Made a new list" <<endl;
    cout << "The list is empty ? " << circ.empty() <<endl;
    
    cout << "displayList()";
    circ.displayList();
    
    cout << "Test find(10) " <<circ.search(10) <<endl;
    
    cout << "Inserting initial link \n";
    circ.insertInitialLink(10);
    cout << "displayList()";
    circ.displayList();
    cout << "\nTest find 10." << circ.search(10)<<endl;
    
    cout << "Inserting 20 after link {10}\n";
    circ.insertAfterValueFound(20, 10);
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nInsertying 15 after link {10}\n";
    circ.insertAfterValueFound(15, 10);
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nInsertying 25 after link {20}\n";
    circ.insertAfterValueFound(25, 20);
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nInserting 25 after link {99}, 99 doesn't exist \n";
    circ.insertAfterValueFound(25, 99);
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nDeleting link that doesn't exist\n";
    cout << "test deleteLink(99): " << circ.deleteLink(99) << endl;
    
    cout << "Trying to delete link 25\n";
    cout << "test deleteLink(25): " << circ.deleteLink(25) << endl;
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nTrying to delete link 20\n";
    cout << "test deleteLink(20): " << circ.deleteLink(20) << endl;
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nTrying to delete link 10\n";
    cout << "test deleteLink(10): " << circ.deleteLink(10) << endl;
    cout << "displayList()";
    circ.displayList();
    
    cout << "\nTrying to delete link 15\n";
    cout << "test deleteLink(15): " << circ.deleteLink(15) << endl;
    cout << "displayList()";
    circ.displayList();
}

/*===OUTPUT===
 Made a new list
 The list is empty ? true
 displayList()The list: is empty
 Test find(10) false
 Inserting initial link
 displayList()The list: {10}
 Test find 10.true
 Inserting 20 after link {10}
 displayList()The list: {10}{20}
 Insertying 15 after link {10}
 displayList()The list: {10}{15}{20}
 Insertying 25 after link {20}
 displayList()The list: {20}{25}{10}{15}
 Inserting 25 after link {99}, 99 doesn't exist
 Value 99 not found.
 displayList()The list: {20}{25}{10}{15}
 Deleting link that doesn't exist
 test deleteLink(99): false
 Trying to delete link 25
 test deleteLink(25): true
 displayList()The list: {20}{10}{15}
 Trying to delete link 20
 test deleteLink(20): true
 displayList()The list: {15}{10}
 Trying to delete link 10
 test deleteLink(10): true
 displayList()The list: {15}
 Trying to delete link 15
 test deleteLink(15): true
 displayList()The list: is empty
 */
