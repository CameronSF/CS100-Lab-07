#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

class Base {
    private:
      Base* leftChild;
      Base* rightChild;
    public:
        /* Constructors */
        Base() { }

        virtual ~Base() {erase();}

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
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

#endif //__BASE_HPP__
