#pragma once
#include <ostream>
#include <string>

class Animal{
public:
    std::string name;
    double temp;
    double breath;
    double heart;

    //C-tor get name of the animal, body temperature, respiratory rate
    //and heart rate - then costruct an animal obect with the values 
    Animal(std::string name, double temp, double breath, double heart);

    //D-tor - default distructor 
    //virtual becase we want the inheriting classes can implement this function 
    //with override
    virtual ~Animal();

    //this function is pure abstruct, we just declaring here 
    //bet not implemnt - the classes that inherit will implement 
   virtual bool check_health() = 0;
};


