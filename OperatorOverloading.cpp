/*
p8.cpp
Tyler Fregoso
3/27/21
Description: Operator Overloading
 */

#include <iostream>
using namespace std;

class Distance
{
private:
    int meter;
public:
    //constructor
    Distance(int m) {meter = m;}
    //Overloading comparison signs:
    // Overload <
    bool operator < (const Distance &d)     {return meter < d.meter;}
    //overlaod ==
    bool operator == (const Distance &d)    {return meter == d.meter;}
    //overload !=
    bool operator != (const Distance &d)    {return meter != d.meter;}
    //overload =
    void operator = (const Distance &d)     {meter = d.meter;}
    //overload >
    bool operator > (const Distance &d)     {return meter > d.meter;}
    //overload <=
    bool operator <= (const Distance &d)    {return meter <= d.meter;}
    //overload >=
    bool operator >= (const Distance &d)    {return meter >= d.meter;}
    
    //Overload math operators:
    // Overload +
    Distance operator + (const Distance &d)
    {
        Distance dist(0);
        dist.meter = this->meter + d.meter; //"this" = d1; d = d2
        return dist;
    }
    
    //overload -
    Distance operator - (const Distance &d)
    {
        Distance dist(0);
        dist.meter = this->meter - d.meter;
        return dist;
    }
    
    //overload *
    Distance operator * (const Distance &d)
    {
        Distance dist(0);
        dist.meter = this->meter * d.meter;
        return dist;
    }
    
    //Overload /
    Distance operator / (const Distance &d)
    {
        Distance dist(0);
        dist.meter = this->meter / d.meter;
        return dist;
    }
    
    //Output: "<<"
    friend ostream &operator << (ostream &output, const Distance &D)
    {
        output << D.meter << "m" << endl;
        return output;
    }
    
    //Input: cin >>
    friend istream &operator >> (istream &input, Distance &D)
    {
        input >> D.meter;
        return input;
    }
};

int main()
{
    Distance d1(4), d2(2), d3(0), d4(4);
    cout << boolalpha;
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "d3 = " << d3 << endl;
    cout << "d4 = " << d4 << endl;
    d4 = d1 + d2;
    cout << "d4 = d1 + d2 = " << d1+d2 <<endl;
    cout << "d2 - d1 = " << d2 - d1 <<endl;
    cout << "d1 / d2 = " << d1 / d2 <<endl;
    cout << "d2 * d1 = " << d2 * d1 <<endl;
    
    cout << "(d1 < d2) is " << (d1 < d2) <<endl;
    cout << "(d2 < d1) is " << (d2 < d1) <<endl;
    cout << "(d2 <= d1) is " << (d2 <= d1) <<endl;
    cout << "(d2 >= d1) is " << (d2 >= d1) <<endl;
    cout << "(d2 > d1) is " << (d2 > d1) <<endl;
    cout << "(d2 == d1) is " << (d2 == d1) <<endl;
    cout << "(d2 != d1) is " << (d2 != d1) <<endl;
    cout << "Enter d4: ";
    cin >> d4;
    cout << "d4 = " << d4 <<endl;
}

/* ===OUTPUT===
 d1 = 4m

 d2 = 2m

 d3 = 0m

 d4 = 4m

 d4 = d1 + d2 = 6m

 d2 - d1 = -2m

 d1 / d2 = 2m

 d2 * d1 = 8m

 (d1 < d2) is false
 (d2 < d1) is true
 (d2 <= d1) is true
 (d2 >= d1) is false
 (d2 > d1) is false
 (d2 == d1) is false
 (d2 != d1) is true
 Enter d4: 100
 d4 = 100m

 */
