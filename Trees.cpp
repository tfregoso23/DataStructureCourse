/*
p11.cpp
Tyler Fregoso
4/24/21
Description: Trees
 */

#include <iostream>
#include <iomanip>
#include <stack> //allows use of stack in displayTree()
using namespace std;

class Node
{
public:
    int data;
    Node *pLeftChild;
    Node *pRightChild;
    Node()
    {
        data = 0;
        pLeftChild = NULL;
        pRightChild = NULL;
    }
    
    void displayNode()
    {
        cout << " {" << data << "}";
    }
};

class Tree
{
private:
    Node *pRoot;
public:
    Tree() { pRoot = NULL;}

    Node* find(int key)
    {
        Node *pCurrent = pRoot;  //start at root
        while (pCurrent->data != key) //run loop of key isn't found
        {
            if (key < pCurrent->data) // If the key is less than current
                pCurrent = pCurrent->pLeftChild; //go left, this is new current
            else                                 // if key is greater than current
                pCurrent = pCurrent->pRightChild; // go RIGHT, this is new current
            if (pCurrent == NULL) // key could not be found (all the way to bottom)
                return NULL;
        }
        return pCurrent; //key is found
    }
    
    void insert (int newData)
    {
        Node *pnewNode = new Node; //new node
        pnewNode->data = newData; //data that goes into new node
        
        if (pRoot == NULL) //if there is no root
            pRoot = pnewNode; //root is new node
        
        else //there is already a root
        {
            Node *pCurrent = pRoot; //start at root
            Node *pParent;
            while (true) //keeps running until hits a return
            {
                pParent = pCurrent;
                if (newData < pCurrent->data) //go left
                {
                    pCurrent = pCurrent->pLeftChild; // new current is left child
                    if (pCurrent == NULL) //if that space isn't occupied
                    {
                        pParent->pLeftChild = pnewNode; // insert new node
                        return;
                    }
                }
                else //same as above but for right child
                {
                    pCurrent = pCurrent->pRightChild;
                    if (pCurrent == NULL)
                    {
                        pParent->pRightChild = pnewNode;
                        return;
                    }
                }
            }
        }
    }
    
    void traverse (int traverseType)
    {
        if (traverseType == 1)
            inOrder(pRoot);
        if (traverseType == 2)
            postOrder(pRoot);
        if (traverseType == 3)
            postOrder(pRoot);
    }
    
    void inOrder (Node *pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            inOrder(pLocalRoot->pLeftChild);
            cout << pLocalRoot->data << " ";
            inOrder(pLocalRoot->pRightChild);
        }
    }
    void preOrder(Node* pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            cout << pLocalRoot->data << " ";
            preOrder(pLocalRoot->pLeftChild);
            preOrder(pLocalRoot->pRightChild);
        }
    }
    
    void postOrder(Node *pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            postOrder(pLocalRoot->pLeftChild);
            postOrder(pLocalRoot->pRightChild);
            cout << pLocalRoot->data << " ";
        }
    }
    
    void minimun()
    {
        Node *pCurrent, *pLast;
        pCurrent = pRoot; //start at root
        while (pCurrent != NULL) // run loop until null
        {
            pLast = pCurrent;
            pCurrent = pCurrent->pLeftChild; // keep going left for minimum
        }
        cout << pLast->data << endl;
    }
    
    void maximum()
    {
        Node *pCurrent, *pLast;
        pCurrent = pRoot; //start at root
        while (pCurrent != NULL) //run until NULL
        {
            pLast = pCurrent;
            pCurrent = pCurrent->pRightChild; //Keep going right for max
        }
        cout << pLast->data << endl;
    }
    
    void displayTree()
    {
        stack <Node*> globalStack;
        globalStack.push(pRoot);
        int nBlanks = 32;
        bool isRowEmpty = false;
        cout <<"......................................................................";
        cout <<endl;
        while(isRowEmpty==false)
        {
            stack<Node*> localStack;
            isRowEmpty = true;
            for (int j=0; j <nBlanks; j++)
                cout << ' ';
            while(globalStack.empty() == false)
            {
                Node* temp = globalStack.top();
                globalStack.pop();
                if(temp != NULL)
                {
                    cout << temp->data;
                    localStack.push(temp->pLeftChild);
                    localStack.push(temp->pRightChild);
                    
                    if ( temp->pLeftChild != NULL || temp->pRightChild != NULL)
                        isRowEmpty = false;
                }
                else
                {
                    cout << "__";
                    localStack.push(NULL);
                    localStack.push(NULL);
                }
                for (int j = 0; j<nBlanks*2-2; j++)
                    cout << ' ';
            } //end while global stack is NOT empty
            cout << endl;
            nBlanks /= 2;
            while(localStack.empty() == false)
            {
                globalStack.push(localStack.top() );
                localStack.pop();
            }
        } //end while isRowEmpty is FALSE
        cout <<"......................................................................";
        cout << endl;
    }
};

int main()
{
    Tree tree;
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(9);
    tree.insert(8);
    
    Node *found = tree.find(3);
    if (found != NULL)
        cout << "Found the node with key 3" << endl;
    else
        cout << "Could not find node with key 3" << endl;
    
    cout << "tree inOrder(): ";
    tree.traverse(1);
    cout << endl;
    tree.displayTree();
    cout << "Smallest value: ";
    tree.minimun();
    cout << "Largest value: ";
    tree.maximum();
}

/*
 ===OUTPUT===
 Found the node with key 3
 tree inOrder(): 1 3 6 8 9
 ......................................................................
                                 6
                 1                              9
         __              3              8              __
 ......................................................................
 Smallest value: 1
 Largest value: 9
 */

