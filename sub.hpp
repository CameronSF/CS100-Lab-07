#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <string>
#include "base.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

class Sub: public Base {
    private:
      Base* leftChild = nullptr;
      Base* rightChild = nullptr;
      std::string sub = "-";
    public:
        Sub(Base* left, Base* right) { leftChild = left; rightChild = right;}

        ~Sub() {
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
        double evaluate() {
          return leftChild->evaluate() - rightChild->evaluate();
        }
        virtual std::string stringify() {
          string expression;
          expression += "(";
          expression += leftChild->stringify();
          expression += sub;
          expression += rightChild->stringify();
          expression += ")";
          return expression;
        }
};

#endif
