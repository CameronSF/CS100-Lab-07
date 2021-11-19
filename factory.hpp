#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include "base.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
class Factory
{
  public:
    Base* parse(char** input, int length)
    {
      Base* root = nullptr;
      Base* temp = nullptr;
      int num;
      if (strcmp(input[0],"*") == 0 || (strcmp(input[0],"/") == 0 || strcmp(input[0],"+") == 0 || (strcmp(input[0],"-")) == 0 || (strcmp(input[0],"**")) == 0))
      {
        return nullptr;
      }
      for (unsigned int i = 0; i < length; i++)
      {
        if (root == nullptr)
        {
          num = stoi(input[i]);
          root = new Op(num);
        }
        else if (isNumber(input[i]))
        {
        }
        else if (strcmp(input[i], "+") == 0)
        {
          if (i+1 >= length)
          {
            return nullptr;
          }
          if (strcmp(input[i+1],"*") == 0 || (strcmp(input[i+1],"/") == 0 || strcmp(input[i+1],"+") == 0 || (strcmp(input[i+1],"-")) == 0 || (strcmp(input[i+1],"**")) == 0))
          {
            return nullptr;
          }
          temp = root;
          root = new Add(temp, new Op(stoi(input[i+1])));
          i++;
          
          
        }
        else if (strcmp(input[i], "-") == 0)
        {
          if (i+1 >= length)
          {
            return nullptr;
          }
          if (strcmp(input[i+1],"*") == 0 || (strcmp(input[i+1],"/") == 0 || strcmp(input[i+1],"+") == 0 || (strcmp(input[i+1],"-")) == 0 || (strcmp(input[i+1],"**")) == 0))
          {
            return nullptr;
          }
          temp = root;
          root = new Sub(temp, new Op(stoi(input[i+1])));
          i++;
          
        }
        else if (strcmp(input[i], "/") == 0)
        {
          if (i+1 >= length)
          {
            return nullptr;
          }
          if (strcmp(input[i+1],"*") == 0 || (strcmp(input[i+1],"/") == 0 || strcmp(input[i+1],"+") == 0 || (strcmp(input[i+1],"-")) == 0 || (strcmp(input[i+1],"**")) == 0))
          {
            return nullptr;
          }
          temp = root;
          root = new Div(temp, new Op(stoi(input[i+1])));
          i++;
          
        }
        else if (strcmp(input[i], "*") == 0)
        {
          if (i+1 >= length)
          {
            return nullptr;
          }
          if (strcmp(input[i+1],"*") == 0 || (strcmp(input[i+1],"/") == 0 || strcmp(input[i+1],"+") == 0 || (strcmp(input[i+1],"-")) == 0 || (strcmp(input[i+1],"**")) == 0))
          {
            return nullptr;
          }
          temp = root;
          root = new Mult(temp, new Op(stoi(input[i+1])));
          i++;
          
        }
        else if (strcmp(input[i], "**") == 0)
        {
          if (i+1 >= length)
          {
            return nullptr;
          }
          if (strcmp(input[i+1],"*") == 0 || (strcmp(input[i+1],"/") == 0 || strcmp(input[i+1],"+") == 0 || (strcmp(input[i+1],"-")) == 0 || (strcmp(input[i+1],"**")) == 0))
          {
            return nullptr;
          }
          temp = root;
          root = new Pow(temp, new Op(stoi(input[i+1])));
          i++;
        }
      }
      return root;    
    }
    bool isNumber(const string& str)
    {
      for (unsigned int i = 0; i < str.length(); i++) 
      {
          if (isdigit(str.at(i)) == 0) 
          {
            return false;
          }
      }
      return true;
    }
};

#endif
