#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>

class Op : public Base {
    private:
	double number;
    public:
        Op(double value) : Base() { number = value; }
        virtual double evaluate() { return number; }
        virtual std::string stringify() { return to_string(number); }
};

#endif //__OP_HPP__
