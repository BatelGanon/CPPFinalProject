#pragma once
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include "Animal.hpp"

//megic number that indicate the minimun and maximum of the body temperature, respiratory rate
//and heart rate using us in function check_health() below 
static constexpr double COW_MIN_TEMP = 38.5;
static constexpr double COW_MAX_TEMP = 39.5;
static constexpr double COW_MIN_BREATH = 26;
static constexpr double COW_MAX_BREATH = 50;
static constexpr double COW_MIN_BEATS = 48;
static constexpr double COW_MAX_BEATS = 84;
static constexpr double MIN_MILK = 30;

//class cow inhert from class animal
class Cow: public Animal{

public:
    double milk;

    //C-tor:
    Cow(std::string name, double temp, double breath, double heart, double litres);

    //D-tor, default distructor 
    //virtual because this calss inhert from Animal and have to implemnt her own distructor
    virtual ~Cow();

    //this function make override to the Anmial pcject function 
    //this function check if the cow is healt and return true is so and false if the cow is sick
    bool check_health() override;
};
