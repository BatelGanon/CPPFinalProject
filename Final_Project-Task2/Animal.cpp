#include <ostream>
#include <string>
#include <stdbool.h>
#include "Animal.hpp"

    //C-tor
    //initilize new animal object with the value and check validation of 
    //the values - respiratory rate and heart rate cant be negative
    //throw an excption if so 
    Animal::Animal(std::string name, double temp, double breath, double heart)
        : name{name}
        , temp{temp}
        , breath{breath}
        , heart{heart}
        { 
            if ((breath < 0) || (heart < 0))
            {
                throw std::invalid_argument{"Invalid argument: a connot be smaller than 0\n"};
            }
        }
    //default constructor -**not sure it should be here     
    Animal::~Animal(){}    
