#pragma once
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include "Animal.hpp"

//megic number that indicate the minimun and maximum of the body temperature, respiratory rate
//and heart rate using us in function check_health() below 
static constexpr double CAT_MIN_TEMP = 38;
static constexpr double CAT_MAX_TEMP = 39.2;
static constexpr double CAT_MIN_BREATH = 16;
static constexpr double CAT_MAX_BREATH = 40;
static constexpr double CAT_MIN_BEATS = 120;
static constexpr double CAT_MAX_BEATS = 140;

//class cat inhert from class animal 
class Cat : public Animal{

    public:
    ////C-tor get name of the cat, body temperature, respiratory rate
    //and heart rate - costruct an cat obect with the values 
    Cat(std::string name, double temp, double breath, double heart);

    //D-tor, default distructor 
    //virtual because this calss inhert from Animal and have to implemnt her own distructor
    virtual ~Cat();

    //this function make override to the Anmial pcject function 
    //this function check if the cat is healt and return true is so and false if the cat is sick
    bool check_health() override;
};