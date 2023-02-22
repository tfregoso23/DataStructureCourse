/*
p12.cpp
Tyler Fregoso
5/1/21
Description: Example of a Hash Table
 */

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class DataItem
{
public:
    int data;
    //----------------------------------------------------------
    DataItem(int newData)
    {
        data = newData;
    } //constructor {}
    //----------------------------------------------------------
}; //end class DataItem

class HashTable
{
private:
    vector<DataItem*> hashArray; // vector holds hash table
    int arraySize;
    DataItem* pNonItem; // for deleted items
    
public:
    //----------------------------------------------------------
    HashTable(int size)
    {
        arraySize = size;
        hashArray.resize(arraySize); //size the vector
        for (int j=0; j<arraySize; j++) //initialize elements
            hashArray[j] = NULL;
        pNonItem = new DataItem(-1); //deleted item key is -1
    }
    //----------------------------------------------------------
    void displayTable()
    {
        cout << "Table: ";
        for (int j=0; j<arraySize; j++)
        {
            if(hashArray[j] != NULL)
                cout << hashArray[j]->data << " ";
            else
                cout << "** ";
        }
        cout << endl;
    }
    //----------------------------------------------------------
    int hashFunc(int key)
    {
        return key % arraySize; //hash function
    }
    //----------------------------------------------------------
    void insert(DataItem* pItem) //insert a DataItem
    //(assumed table is not full)
    {
        int key = pItem->data; //extract key
        int hashVal = hashFunc(key); //hash the key
                                     //until empty cell or -1
        while(hashArray[hashVal] != NULL &&
              hashArray[hashVal]->data != -1)
        {
            ++hashVal; //go to next cell
            hashVal %= arraySize; //wraparound if necessary
        }
        hashArray[hashVal] = pItem; //insert item
        //end insert()
    }
    //----------------------------------------------------------
    DataItem* remove (int key)  //remove a DataItem
    {
        int hashVal = hashFunc(key);                            //hash the key
        while ( hashArray [hashVal] != NULL)                    //until empty cell
        {
            if (hashArray[hashVal]->data == key )               //found the key
            {
                DataItem* pTemp = hashArray[hashVal];           //save item
                hashArray[hashVal] = pNonItem;                  //delete item
                return pTemp;                                   //return item
            }
            ++hashVal;                                          // go to next cell
            hashVal %= arraySize;                               //wraparound if necessary
        }
        return NULL;                                            // cant find item
    }
    //----------------------------------------------------------
    DataItem* find (int key)                                    //find item with key
    {
        int hashVal = hashFunc(key);                            //hash the key
        while (hashArray[hashVal] != NULL)                      //until cell empty
        {
            if (hashArray[hashVal]->data == key)                //found the key?
                return hashArray[hashVal];                      // yes return item
            ++hashVal; // go next cell
            hashVal %= arraySize;                               //wraparound if necessary
        }
        return NULL;                                            //cant find item
    }
    //----------------------------------------------------------
};

int main()
{
    DataItem* pDataItem;
    int aKey, size, n, keysPerCell;
    time_t aTime;
    char choice = 'b';
    //get sizes
    cout << "Enter size of hash table: ";
    cin >> size;
    cout << "Enter initial number of items: ";
    cin >> n;
    keysPerCell = 10;
    
    HashTable theHashTable(size); //makes table
    srand( static_cast<unsigned>(time(&aTime)) ); //make a random list of numbers
    for (int j = 0; j< n; j++)
    {
        aKey = rand() % (keysPerCell*size); //r
        pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
    }
    while (choice != 'x')   //interact with user
    {
        cout << "Enter first lette of "
        << "show, insert, delete, or find: ";
        char choice;
        cin >> choice;
        switch(choice)
        {
            case 's':
                theHashTable.displayTable();
                break;
            case 'i':
                cout << "Enter key value to insert: ";
                cin >> aKey;
                pDataItem = new DataItem(aKey);
                theHashTable.insert(pDataItem);
                break;
            case 'd':
                cout << "Enter key value to delete: ";
                cin >> aKey;
                theHashTable.remove(aKey);
                break;
            case 'f':
                cout << "Enter key value to find: ";
                cin >> aKey;
                pDataItem = theHashTable.find(aKey);
                if (pDataItem != NULL)
                    cout << "Found " << aKey << endl;
                else
                    cout << "Could not find " << aKey <<endl;
                break;
            default:
                cout << "Invalid entry\n";
        } //end switch
    } //end while
} //end main()

/*
===OUTPUT===
 Enter size of hash table: 12
 Enter initial number of items: 8
 Enter first lette of show, insert, delete, or find: s
 Table: 48 ** 86 51 100 88 98 75 104 ** ** **
 Enter first lette of show, insert, delete, or find: f
 Enter key value to find: 66
 Could not find 66
 Enter first lette of show, insert, delete, or find: f
 Enter key value to find: 100
 Found 100
 Enter first lette of show, insert, delete, or find: i
 Enter key value to insert: 1
 Enter first lette of show, insert, delete, or find: s
 Table: 48 1 86 51 100 88 98 75 104 ** ** **
 Enter first lette of show, insert, delete, or find: d
 Enter key value to delete: 98
 Enter first lette of show, insert, delete, or find: s
 Table: 48 1 86 51 100 88 -1 75 104 ** ** **
 
 */
