#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <string>
#include "base.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

class Add: public Base {
    private:
      Base* leftChild = nullptr;
      Base* rightChild = nullptr;
      std::string add = "+";
    public:
        /* Constructors */
        Add(Base* left, Base* right) { leftChild = left; rightChild = right;}

        ~Add() {
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
          return leftChild->evaluate() + rightChild->evaluate();
        };
        virtual std::string stringify() {
          string expression;
          expression += "(";
          expression += leftChild->stringify();
          expression += add;
          expression += rightChild->stringify();
          expression += ")";
          return expression;
        };
};

#endif //__BASE_HPP__
