#include "Vet.hpp"
#include "Dog.hpp"
#include <iostream>
#include <typeinfo>
#include <typeindex>

//default contructor , initilize with 0
Vet::Vet()
    : animals{}
    { } 

//get pointer to rvalue of animal object and add it to the animals vector
void Vet::add_animal(Animal * &&ref){

    animals.emplace_back(ref);

}

//print the sick animals
//go througth the animals vector and call to the function check_health for any object in the vector
//if the function return false -> it mean the animal is sick and it print it for the screen 
void Vet::show_sick(){

    for(auto iter = animals.begin();iter != animals.end();iter++){
        if( ! (*iter)->check_health() )
        {
            std::cout<< "The animal : " <<(*iter)->name <<" is sick " <<std::endl;
        }
    }

}

//print the sick dogs
//it goes through the vector and checks for each object if the function check_health returns false && the animal object is type of
//dog -if both conditions are met -> it mean the animal is sick dog and it print it for the screen 
void Vet::show_sick_dogs(){

    for(auto it = animals.begin() ;it != animals.end(); it++)
    {
        //typeid return typeinfo and equal him to the other 
        if( ( ! (*it)->check_health()) && (typeid(*it->get()) == typeid(Dog)))
        {
            std::cout<<(*it)->name<<std::endl;
        } 
    } 
}