#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <string>
#include "base.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

class Div: public Base {
    private:
      Base* leftChild = nullptr;
      Base* rightChild = nullptr;
      std::string div = "/";
    public:
        /* Constructors */
        Div(Base* left, Base* right) { leftChild = left; rightChild = right;}

        ~Div() {
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
          return leftChild->evaluate() / rightChild->evaluate();
        };
        virtual std::string stringify() {
          string expression;
          expression += "(";
          expression += leftChild->stringify();
          expression += div;
          expression += rightChild->stringify();
          expression += ")";
          return expression;
        };
};

#endif //__BASE_HPP__
