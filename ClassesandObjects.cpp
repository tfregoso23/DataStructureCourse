/*
p2.cpp
Tyler Fregoso
2/18/21
Description: Type up sample OOP and add Propert weight as well as actions showWeight and changeWeight
 */

#include <iostream>
using namespace std;

class Person
{
    private: //age is private so we cannot access via tyler.age
        int age;
        float weight; //private property weight
    public: //provides way to access and show age
        void showAge();
        void changeAge(int newAge);
        void showWeight();
        void changeWeight(float newWeight);
        Person(); //Default constructor
        Person(int newAge); //Explicit constructor
};

void Person :: showAge()
{
    cout << age << endl;
}

void Person :: changeAge(int newAge)
{
    age = newAge;
}

void Person :: showWeight()
{
    cout << weight << endl;
}

void Person :: changeWeight(float newWeight)
{
    weight = newWeight;
}

Person :: Person() // default constructor
{
    age = 101; //defaults age to 101
    weight = 100.0; // defaults weight to 100
}

Person :: Person(int newAge) // explicit constructor
{
    age = newAge;
}

int main()
{
    Person tyler; //Default constructor
    tyler.showAge(); //uses default 101
    tyler.changeAge(20); //changes age to 20
    tyler.showAge(); //shows updated age
    tyler.showWeight(); // show default weight set up as 100
    tyler.changeWeight(160.2); //changes weight to 160.2
    tyler.showWeight(); //shows new weight 160.2
    
    Person child(8); //explicit constructor
    child.showAge();
}

/*===OUTPUT===
 101
 20
 100
 160.2
 8
 Program ended with exit code: 0
 */
