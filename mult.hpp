#ifndef __MULT_HPP__
#define __MULT_HPP__

#include <string>
#include "base.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

class Mult: public Base {
    private:
      Base* leftChild = nullptr;
      Base* rightChild = nullptr;
      std::string mult = "*";
    public:
        /* Constructors */
        Mult(Base* left, Base* right) { leftChild = left; rightChild = right;}

        ~Mult() {
          erase();
        }

        void erase()
        {
          if (leftChild == nullptr && rightChild == nullptr)
          {
            return;
          }
          leftChild->erase();
          rightChild->erase();
          delete leftChild;
          delete rightChild;
        }
        /* Pure Virtual Functions */
        double evaluate() {
          return leftChild->evaluate() * rightChild->evaluate();
        }
        virtual std::string stringify() {
          string expression;
          expression += "(";
          expression += leftChild->stringify();
          expression += mult;
          expression += rightChild->stringify();
          expression += ")";
          return expression;
        }
};

#endif //__BASE_HPP__

