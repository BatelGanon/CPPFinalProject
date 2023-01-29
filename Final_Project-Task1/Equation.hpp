#include <iostream>
#include <ostream>


class Equation{
private:
    double m_a;
    double m_b;
    double m_c;
    double *m_solutions = 0;
    static constexpr double NO_SOLUTION = 0;
    std::size_t m_solutions_size{};


public:

    //C-TOR'S
    Equation(double a, double b, double c);

    // GETTERS AND SETTERS
    double get_a()const;
    double get_b()const;
    double get_c()const;
    double const *get_solutions()const; 
    std::size_t get_solutions_size()const; 

    //the values of solutions and soultions_size needs to be updated accordingly
    void set_a(double val);
    void set_b(double val);
    void set_c(double val);

    // update_solutions - TODO?
    void update_solution();

    //rule of five

    //d-tor:
    ~Equation();

    //copy ctor:
    Equation(const Equation &o);

    //copy assignment 
    Equation& operator =(Equation &o); 

    //move constructor
    Equation(Equation&& oter);

    //move assignment
    Equation& operator =(Equation&& rhs);

    //helper function
    void swap(Equation &o);

    friend std::ostream &operator << (std::ostream &out, Equation const &o);
    Equation operator +(Equation const &o);
    Equation operator +(const double d)const;
    friend Equation operator +(double l,Equation const &r);
};
