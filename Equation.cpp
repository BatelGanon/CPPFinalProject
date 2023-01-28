#include "Equation.hpp"
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
#include <stdexcept>
#include <bits/stdc++.h>

//C-TOR'S
//getting 3 argument
//initializes the array to size 2 with 0 values (megic number) 
//throw exception if a=0
//call to update solution function to caculate the new Equation
Equation::Equation(double a, double b, double c)
    :m_a{a}
    ,m_b{b}
    ,m_c{c}
    ,m_solutions_size{}
    ,m_solutions{}
    {
        //main - exeptions  
        if (a==0)
        {
            throw std::invalid_argument{"Illegal argument: a connot be zero\n"};
        }
        
       m_solutions = new double[2]{NO_SOLUTION}; 
       update_solution(); 
    }


//getter functions - return the value of argument
//const because the value cant change
double Equation::get_a() const{return m_a;}
double Equation::get_b() const{return m_b;}
double Equation::get_c() const{return m_c;}
double const * Equation::get_solutions()const{return m_solutions;}
std::size_t Equation::get_solutions_size() const{ return m_solutions_size;}

//setter functions - set new value
//send to update solutions to caculate the equation with the new value
//set_a function also throw exception if we get a = 0
void Equation::set_a(double val){
    if (val==0)
        {
            throw std::invalid_argument{"Illegal argument: a connot be zero\n"};
        }
    m_a = val;    
    update_solution();
}
void Equation::set_b(double val){
    m_b = val;
    update_solution();
}
void Equation::set_c(double val){
    m_c = val;
    update_solution();
}    

//The next 5 methodes is rules of 5: 

//copy c-tor:
Equation::Equation(const Equation &o)
    :Equation{o.m_a, o.m_b,o.m_c}
    {
        m_solutions = o.m_solutions;
        m_solutions_size = o.m_solutions_size;
        //check if o should be delete 
    }

//d-tor:
Equation::~Equation(){
    delete[] m_solutions;
    m_solutions = nullptr;   
}

//copy assingment
//operator overloadindg - using copy and swap idiom
//checking if the object is already equal - so we should do nothing
//else - we using swap function to swap between the objects
//the other object will delete by the d-tor
Equation& Equation::operator =(Equation &o){
        if(this != &o){ 

            swap(o);
        }   
    return *this;
} 

//move constructor - TODO
Equation::Equation(Equation&& other){

    m_a = other.m_a;
    m_b = other.m_b;
    m_c = other.m_c;
    m_solutions_size = other.m_solutions_size;
    m_solutions = other.m_solutions;
    other.m_solutions = nullptr;

}

//move assignment -TODO
Equation& Equation::operator =(Equation&& rhs){

    if(this != &rhs){
        m_a = rhs.m_a;
        m_b = rhs.m_b;
        m_c = rhs.m_c;
        m_solutions_size = rhs.m_solutions_size;
        if(m_solutions)
        {
            delete[] m_solutions;
        }
        m_solutions = rhs.m_solutions;
        rhs.m_solutions = nullptr;
    }
    return *this;
}

//helper function
void Equation::swap(Equation &o){
    m_a = o.m_a;  
    m_b = o.m_b; 
    m_c = o.m_c; 
    for (size_t i = 0; i < m_solutions_size; i++)
    {
        m_solutions[i] = o.m_solutions[i]; 
    }
}


std::ostream& operator << (std::ostream &out, Equation const &o) {
    out << std::setprecision(3)<< o.m_a <<"x^2 + "<< std::setprecision(13) << o.m_b << "x + " << std::setprecision(3)<<o.m_c <<" = 0\n";
    return out;
}

//operator overloading for + 
//send to constructor the value of the two arguments
Equation Equation::operator +(Equation const &o){
    
    return Equation{m_a + o.m_a, m_b + o.m_b,m_c + o.m_c};
}

//operator overloading for + 
//send to constructor the same value of a and b , and for c send the value of c + the new value
Equation Equation::operator +(const double d)const{
    
    return Equation{m_a, m_b, m_c + d};
}

////operator overloading for +  
//double from the left and the object from right 
//using the operator + implemention - just get 2 value 
// ****explain why is friend function!!!!!!!!!************** 
Equation operator +(double l, const Equation& r){
    
   return Equation{r.get_a(),r.get_b(),r.get_c() + l};
}

//caculate the Equation - 
//caculate the delta and then check how many solutions we will get (by the value od delta)
void Equation::update_solution(){
    int check = pow(m_b,2) -4*m_a*m_c;  
    m_solutions_size = check;
        if (check > 0)
        { 
            m_solutions[0]= ((-m_b)+sqrt(check)) / (2*m_a); 
            m_solutions[1]= ((-m_b)-sqrt(check)) / (2*m_a);
        }
        else if (check == 0)
        { 
            m_solutions[0]= (-m_b)/(2*m_a); 
            m_solutions[1]= (-m_b)/(2*m_a);
        }
        else if (check < 0)
        { 
            m_solutions[0]=  NO_SOLUTION; 
            m_solutions[1]= NO_SOLUTION;
        }
} 
