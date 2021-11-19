#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

class Rand : public Base {
    double number;

    public:
        Rand() : Base() { srand(time(0)); number =  rand() % 100; }
        virtual double evaluate() { return number; }
        virtual std::string stringify() { return to_string(number); }
};

#endif //__OP_HPP__

