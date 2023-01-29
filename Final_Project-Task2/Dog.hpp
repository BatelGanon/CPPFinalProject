#pragma once
#include <ostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include "Animal.hpp"


//megic number that indicate the minimun and maximum of the body temperature, respiratory rate
//and heart rate using us in function check_health() below 
static constexpr double DOG_MIN_TEMP = 38;
static constexpr double DOG_MAX_TEMP = 39.2;
static constexpr double DOG_MIN_BREATH = 10;
static constexpr double DOG_MAX_BREATH = 35;
static constexpr double LARGE_DOG_MIN_BEATS = 60;
static constexpr double LARGE_DOG_MAX_BEATS = 100;
static constexpr double SMALL_DOG_MIN_BEATS = 100;
static constexpr double SMALL_DOG_MAX_BEATS = 140;

//class dog inhert from class animal
class Dog : public Animal{

public: 
   
    bool is_large;

    ////C-tor get name of the dog, body temperature, respiratory rate,
    // heart rate  and if the dog is small or large(true is small)
    //costruct a dog obect with the values 
    Dog(std::string name, double temp, double breath, double heart, bool is_large);

    //D-tor, default distructor 
    //virtual because this calss inhert from Animal and have to implemnt her own distructor
    virtual ~Dog();

    //this function make override to the Anmial pcject function 
    //this function check if the dog is healt and return true is so and false if the dog is sick
    bool check_health() override;
};