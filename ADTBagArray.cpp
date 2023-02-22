/*
p4.cpp
Tyler Fregoso
2/28/21
Description: Write and test functions for ADT Bag
 */

#include <iostream>
using namespace std;

class Item
{
private:
    string name;
    double cost;
public:
    Item() //Default
    {
        name = "";
        cost = 0.0;
    }
    
    Item (string newName, double newCost) // Explicit
    {
        name = newName;
        cost = newCost;
    }
        
    void show() { cout << "- " << name << " $" << cost <<endl;}
    
    string get_name() {return name;}
    double get_cost() {return cost;}
    
    void set_item(string newName, double newCost)
    {
        name = newName;
        cost = newCost;
    }
    
    void setItem (Item item)
    {
        name = item.get_name();
        cost = item.get_cost();
    }
};

class Bag
{
private:
    Item *items; //Dynamic array
    int number_items;
    int max;
    
public:
    Bag(int Max)
    {
        items = new Item[Max]; //an array of items
        number_items = 0; //Initializes index as 0
        max = Max; // size of array
    }
    
    void insert_item(string name, double cost)
    {
        items[number_items].set_item(name, cost);
        number_items++;
    }
    
    void insertItem(Item item)
    {
        items[number_items].setItem(item);
        number_items++;
    }
    
    int size() {return max;}
    
    void showItems()
    {
        for (int i = 0; i < number_items; i++)
            items[i].show();
    }
    
    void delete_first()
    {
        //shift all elements one left
        for (int i = 0; i < max-1; i++)
            items[i] = items[i-1];
        number_items--;
    }
    
    bool contains (string name_to_find)
    {
        for (int i = 0; i < number_items; i++)
            if(name_to_find == items[i].get_name())
                return true;
        return false;
    }
    
    void sort_by_cost_ascending() // bubble sort
    {
        for (int i = 0; i < number_items-1; i++)
            for (int j = 0 ; j < number_items; j++)
            {
                if (items[j].get_cost() > items[j+1].get_cost())
                    swap(j,j+1);
            }
    }
    
    void swap(int index1, int index2)
    {
        Item temp = items[index1];
        items[index1] = items[index2];
        items[index2] = temp;
    }
    
    void most_expensive()//Shows the most expensive items
    {
        int expensive = 0; //variable that determines most expensive
        for (int i = 1; i < number_items; i++)
        {
            //If item is more expensive then previous item, then this is now most expensive
            if (items[i].get_cost() > items[expensive].get_cost())
                expensive = i;
        }
        cout << "Most expensive item is: ";
        cout<< items[expensive].get_name();
        cout << " $"<< items[expensive].get_cost() <<endl;
    }
    
    void show_reverse() //shows items in reverse
    {
        for(int i = number_items-1; i >= 0; i--)
            items[i].show();
    }
    
    void get_frequency(Item item)
    {
        int counter = 0; //starts counter at 0
        for (int i = 0; i < number_items; i++)
        {
            //goes through array, anytime names match 1 is added to counter
            if (items[i].get_name() == item.get_name())
                counter++;
        }
        cout << item.get_name() << " appears " << counter<< " times."<<endl;
    }
    
    bool delete_item(Item item)
    {
        //Looks for item, breaks loop when item is found
        int item_to_delete;
        for (item_to_delete = 0; item_to_delete < number_items; item_to_delete++)
            if (items[item_to_delete].get_name() == item.get_name())
                break;
        
        if (item_to_delete == number_items) //if item isnt found
            return false;
        
        //moves everything one left and resizes items in array
        for (int i = item_to_delete; i <number_items-1; i++)
            items[i] = items[i+1];
        number_items--;
        return true;
    }
    
    int get_index_of(Item item)
    {
        int index;
        //searches through list and breaks once item is found
        for (index = 0; index < number_items; index++)
            if (items[index].get_name() == item.get_name())
                break;
        return index; //return index number
    }
    
    double sum_of_all()
    {
        //returns sum of cost of all items in bag
        double cost_sum = 0.0;
        for (int i = 0; i< number_items; i++)
        {
            cost_sum+= items[i].get_cost();
        }
        return cost_sum;
    }
    
};


int main()
{
    //Test
    cout << "Testing Item: ";
    Item fujiApple("Fuji Apple", 4.99);
    fujiApple.show();
    
    int max_items_in_bag = 4;
    Bag bag(max_items_in_bag);
    
    cout << "\nAdded the following items to the bag:\n";
    bag.insert_item("Oranges", 5.00);
    bag.insertItem(fujiApple);
    
    Item cheese("Cheese", 6.79);
    bag.insertItem(cheese);
    Item olives("Olives", 4.49);
    bag.insertItem(olives);
    bag.insertItem(fujiApple);
    bag.insert_item("Bananas", 0.79);
    bag.showItems();
    bag.most_expensive();
    cout<<endl;
    
    cout << "Showing items in reverse order: "<<endl;
    bag.show_reverse();
    bag.get_frequency(fujiApple);
    cout<<endl;
    
    cout << "Showing items with cheese deleted:" <<endl;
    bag.delete_item(cheese);
    bag.showItems();
    cout << "Index of Olives: " <<bag.get_index_of(olives)<<endl;
    cout << "Cost of all items in bag: $" << bag.sum_of_all()<<endl;
}

/* ===OUTPUT ===
 Testing Item: - Fuji Apple $4.99

 Added the following items to the bag:
 - Oranges $5
 - Fuji Apple $4.99
 - Cheese $6.79
 - Olives $4.49
 - Fuji Apple $4.99
 - Bananas $0.79
 Most expensive item is: Cheese $6.79

 Showing items in reverse order:
 - Bananas $0.79
 - Fuji Apple $4.99
 - Olives $4.49
 - Cheese $6.79
 - Fuji Apple $4.99
 - Oranges $5
 Fuji Apple appears 2 times.

 Showing items with cheese deleted:
 - Oranges $5
 - Fuji Apple $4.99
 - Olives $4.49
 - Fuji Apple $4.99
 - Bananas $0.79
 Index of Olives: 2
 Cost of all items in bag: $20.26
 */
