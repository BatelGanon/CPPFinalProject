#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "Animal.hpp"

class Vet{
public:

//for singleton
    static Vet& getInstance()
        {
            static Vet instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
private:
    //want to make sure they
    // are inaccessible(especially from outside), otherwise, you may accidentally get copies of
    // your singleton appearing.
    Vet(); 
    Vet(Vet const&);
    void operator =(Vet const&);

    //vector of smart pointer uniqe of animals object - it contains different types of animals 
    std::vector<std::unique_ptr<Animal> > animals;

public:

// function get vector of an animals and animal as rvalue and add him to the vector
void add_animal(Animal * &&ref);

//go trougth the animals vector and print the sick animals 
void show_sick();

//go througth the animals vector and print all the sick dogs
void show_sick_dogs();

};