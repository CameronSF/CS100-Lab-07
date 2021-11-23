#include <iostream>
#include "base.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "factory.hpp"
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {

  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(argv+1,argc-1);
  if (tree == nullptr)
  {
    cout << "Invalid" << endl;
    return 0;
  }
  cout << tree->stringify() << " = " << tree->evaluate()<<endl;
  return 0;
} 
