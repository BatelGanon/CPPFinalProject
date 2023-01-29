#include <string>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Cat.hpp"


    //constructor get name of a cat, body temperature, respiratory rate
    //and heart rate - send the values to Anmial constructor and build as Cat object  
    Cat::Cat(std::string name, double temp, double breath, double heart)
        : Animal{name, temp, breath, heart}
        { }

    //default constructor -**not sure it should be here 
    Cat::~Cat(){};

    //this function check if the body temperature, respiratory rate
    //and heart rate is in the range then return true if all this values in the range ->
    //it means the cat is healt and false if the cat is sick
    bool Cat::check_health() {
        if ((CAT_MIN_TEMP <= temp && temp <= CAT_MAX_TEMP)
        &&  (CAT_MIN_BREATH <= breath && breath <= CAT_MAX_BREATH)
        &&  (CAT_MIN_BEATS <= heart && heart <= CAT_MAX_BEATS))
        {
            return true;
        }
        else return false;
    }

