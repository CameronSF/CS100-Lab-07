#ifndef __POW_HPP__
#define __POW_HPP__

#include <string>
#include "base.hpp"
#include <iostream>
#include <cstdlib> 
#include <cmath>

using namespace std;

class Pow: public Base {
    private:
      Base* leftChild = nullptr;
      Base* rightChild = nullptr;
      std::string pow1 = "**";
    public:
        Pow(Base* left, Base* right) { leftChild = left; rightChild = right;}

        ~Pow() {
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
          return pow(leftChild->evaluate(), rightChild->evaluate());
        }
    
        virtual std::string stringify() {
          string expression;
          expression += "(";
          expression += leftChild->stringify();
          expression += pow1;
          expression += rightChild->stringify();
          expression += ")";
          return expression;
        }
};

#endif
