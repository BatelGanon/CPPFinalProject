#include <ostream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include "Dog.hpp"


    //constructor get name of a dog, body temperature, respiratory rate
    //and heart rate and if the dog is small or large-
    // send the values to Anmial constructor and initilize the is_large argiment and build as dog object  
    Dog::Dog(std::string name, double temp, double breath, double heart, bool is_large)
        : Animal{name, temp, breath, heart}
        , is_large{is_large}
        { }

    //default constructor -**not sure it should be here 
    Dog::~Dog(){};

    //this function check if the body temperature, respiratory rate and heart rate
    //is in the range then return true if all this values in the range (considering whether the dog is large or small) 
    //->it means the dog is healt and false if the dog is sick
    bool Dog::check_health() {
        
        if((DOG_MIN_TEMP <= temp && temp <= DOG_MAX_TEMP)
        && (DOG_MIN_BREATH <= breath && breath <= DOG_MAX_BREATH))
        {
            if(is_large)
            {
                if((LARGE_DOG_MIN_BEATS <= heart && heart <= LARGE_DOG_MAX_BEATS ))
                {
                    return true;
                }
            }
            else
            {
                if((SMALL_DOG_MIN_BEATS <= heart && heart <= SMALL_DOG_MAX_BEATS))
                {
                    return true;
                }            
            }
        }    
    return false;
    }
