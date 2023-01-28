#include <ostream>
#include <iostream>
#include <stdexcept>
#include "Equation.hpp"


int main()
{
    try{
    Equation e1{3,3,9};
    Equation e2{1,4,6};
   // Equation e3 = e1 + e2;
    e1 = 1 + e1;
    //operator<<(std::cout, e3);
    operator<<(std::cout, e1);
    operator<<(std::cout, e2);
    std::cout<<"solution 1:"<<e1.get_solutions()[0]<<std::endl;
    std::cout<<"solution 2:"<<e1.get_solutions()[1];
    }
    catch(std::invalid_argument &e){
        std::cout <<"Caught an error!"<<std::endl;
        std::cout << e.what() << std::endl;
    }
    /*
     catch (...){
        std::cout << "unexpected error\n";
        return 1; //exit failure
    }
    */
   std::cout<< "\ntesting of the task from here:\n";

   using namespace std;
    Equation eq(10,20,30);
    cout << eq << endl;
    //should print: 10X^2 + 20X + 30 = 0
    cout << eq.get_solutions_size() << endl;
    //should print 0
    eq = -20 + eq;
    cout << eq << endl;
    //should print: 10X^2 + 20X + 10 = 0
    cout << eq.get_solutions_size() << endl;
    //should print 1
    cout << eq.get_solutions()[0] << endl;
    //should print -1
    cout << Equation(1,5,3) + Equation(2,6,4) << endl;
    //should print: 3X^2 + 11X + 7 = 0
    eq = Equation(1,3,-4);
    cout << eq << endl;
    //should print 1X^2 + 3X + -4 = 0
    cout << eq.get_solutions_size() << endl;
    //should print 2
    cout << "X1 = " << eq.get_solutions()[0] << endl;
    //should print: X1 = 1
    cout << "X2 = " << eq.get_solutions()[1] << endl;
    //should print: X2 = -4



    return 0;
}
