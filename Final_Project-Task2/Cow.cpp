#include <string>
#include <stdio.h>
#include <stdbool.h>
#include "Cow.hpp"


//constructor get name of a dog, body temperature, respiratory rate
//and heart rate and if the dog is small or large-
//send the values to Anmial constructor and initilize the is_large argiment and build as dog object  
Cow::Cow(std::string name, double temp, double breath, double heart, double litres)
    : Animal{name, temp, breath, heart}
    , milk{litres}
    { 
            if (milk < 0)
            {
                throw std::invalid_argument{"Invalid argument: a connot be smaller than 0\n"};
            }        
    }
    
//default constructor -**not sure it should be here
Cow::~Cow(){}


//this function check if the body temperature, respiratory rate, heart rate and milk production (30 or more per day)
//is in the range then return true if all this values in the range 
//->it means the cow is healt and false if the cow is sick
bool Cow::check_health(){

    if((COW_MIN_TEMP <= temp && temp <= COW_MAX_TEMP)
    &&(COW_MIN_BREATH <= breath && breath <= COW_MAX_BREATH)
    &&(COW_MIN_BEATS <= heart && heart <= COW_MAX_BEATS)
    &&(milk >= MIN_MILK))
    {
        return true;
    }  
        return false;
}