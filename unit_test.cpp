#include "gtest/gtest.h"
#include "base.hpp"
#include "factory.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <cstdlib>
#include "op_test.hpp"
using namespace std;

TEST(MultTest, MultEvaluateNonZero) {
    Op* value1 = new Op(6);
    Op* value2 = new Op(8);
    Base* test = new Mult(value1,value2);
    EXPECT_EQ(test->evaluate(), 48);
}

TEST(MultTest, MultEvaluateNeg) {
    Op* value1 = new Op(6);
    Op* value2 = new Op(-8);
    Base* test = new Mult(value1, value2);
    EXPECT_EQ(test->evaluate(), -48);
}

TEST(MultTest, MultEvaluateZero) {
    Op* value1 = new Op(0);
    Op* value2 = new Op(0);
    Base* test = new Mult(value1, value2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringify) 
{
    Op* value1 = new Op(1);
    Op* value2 = new Op(2);
    Base* test = new Mult(value1, value2);
    EXPECT_EQ(test->stringify(), "(1.000000*2.000000)");
}

TEST(DivTest, DivEvaluateNonZero) {
    Op* value1 = new Op(48);
    Op* value2 = new Op(8);
    Base* test = new Div(value1, value2);
    EXPECT_EQ(test->evaluate(), 6);
}

TEST(DivTest, DivEvaluateNeg) {
    Op* value1 = new Op(48);
    Op* value2 = new Op(-8);
    Base* test = new Div(value1, value2);
    EXPECT_EQ(test->evaluate(), -6);
}

TEST(DivTest, DivEvaluateZero) {
    Op* value1 = new Op(0);
    Op* value2 = new Op(1);
    Base* test = new Div(value1, value2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivStringify) 
{
    Op* value1 = new Op(1);
    Op* value2 = new Op(2);
    Base* test = new Div(value1, value2);
    EXPECT_EQ(test->stringify(), "(1.000000/2.000000)");
}

TEST(AddTest, AddEvaluateNonZero) {
    Op* value1 = new Op(6);
    Op* value2 = new Op(8);
    Base* test = new Add(value1, value2);
    EXPECT_EQ(test->evaluate(), 14);
}

TEST(AddTest, AddEvaluateNeg) {
    Op* value1 = new Op(6);
    Op* value2 = new Op(-8);
    Base* test = new Add(value1, value2);
    EXPECT_EQ(test->evaluate(), -2);
}

TEST(AddTest, AddEvaluateZero) {
    Op* value1 = new Op(0);
    Op* value2 = new Op(0);
    Base* test = new Add(value1, value2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddStringify) 
{
    Op* value1 = new Op(1);
    Op* value2 = new Op(2);
    Base* test = new Add(value1, value2);
    EXPECT_EQ(test->stringify(), "(1.000000+2.000000)");
}

TEST(SubTest, SubEvaluateNonZero) {
    Op* value1 = new Op(8);
    Op* value2 = new Op(6);
    Base* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(SubTest, SubEvaluateNeg) {
    Op* value1 = new Op(6);
    Op* value2 = new Op(-8);
    Base* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 14);
}

TEST(SubTest, SubEvaluateZero) {
    Op* value1 = new Op(0);
    Op* value2 = new Op(0);
    Base* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubStringify) 
{
    Op* value1 = new Op(1);
    Op* value2 = new Op(2);
    Base* test = new Sub(value1, value2);
    EXPECT_EQ(test->stringify(), "(1.000000-2.000000)");
}

TEST(PowTest, PowEvaluateNonZero) {
    Op* value1 = new Op(2);
    Op* value2 = new Op(3);
    Base* test = new Pow(value1, value2);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(PowTest, PowEvaluateNeg) {
    Op* value1 = new Op(2);
    Op* value2 = new Op(-3);
    Base* test = new Pow(value1, value2);
    EXPECT_EQ(test->evaluate(), 0.125);
}

TEST(PowTest, PowEvaluateZero) {
    Op* value1 = new Op(0);
    Op* value2 = new Op(0);
    Base* test = new Pow(value1, value2);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowStringify) 
{
    Op* value1 = new Op(1);
    Op* value2 = new Op(2);
    Base* test = new Pow(value1, value2);
    EXPECT_EQ(test->stringify(), "(1.000000**2.000000)");
}

TEST (RandTest, RandNumber){
   Rand* value1 = new Rand();
   EXPECT_NE(value1->evaluate(), 100);
}

TEST (StringTest, Add)
{
  char* test_val[3]; test_val[0] = "4"; test_val[1] = "+"; test_val[2] = "5";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 3);
  EXPECT_EQ(tree->stringify(), "(4.000000+5.000000)");
  EXPECT_EQ(tree->evaluate(), 9);
}


TEST (StringTest, Sub)
{
  char* test_val[3]; test_val[0] = "4"; test_val[1] = "-"; test_val[2] = "5";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 3);
  EXPECT_EQ(tree->stringify(), "(4.000000-5.000000)");
  EXPECT_EQ(tree->evaluate(), -1);
}

TEST (StringTest, Mult)
{
  char* test_val[3]; test_val[0] = "4"; test_val[1] = "*"; test_val[2] = "5";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 3);
  EXPECT_EQ(tree->stringify(), "(4.000000*5.000000)");
  EXPECT_EQ(tree->evaluate(), 20);
}

TEST (StringTest, Divide)
{
  char* test_val[3]; test_val[0] = "20"; test_val[1] = "/"; test_val[2] = "5";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 3);
  EXPECT_EQ(tree->stringify(), "(20.000000/5.000000)");
  EXPECT_EQ(tree->evaluate(), 4);
}

TEST (StringTest, Pow)
{
  char* test_val[3]; test_val[0] = "6"; test_val[1] = "**"; test_val[2] = "3";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 3);
  EXPECT_EQ(tree->stringify(), "(6.000000**3.000000)");
  EXPECT_EQ(tree->evaluate(), 216);
}

TEST (StringTest, AllTest)
{
  char* test_val[11]; test_val[0] = "6"; test_val[1] = "**"; test_val[2] = "3"; test_val[3] = "+"; test_val[4] = "7"; test_val[5] = "-"; test_val[6] = "2"; test_val[7] = "*"; test_val[8] = "5"; test_val[9] = "/"; test_val[10] = "2";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 11);
  EXPECT_EQ(tree->stringify(), "(((((6.000000**3.000000)+7.000000)-2.000000)*5.000000)/2.000000)");
  EXPECT_EQ(tree->evaluate(), 552.5);
}



TEST (StringTest, InvalidFront)
{
  char* test_val[2]; test_val[0] = "+"; test_val[1] = "3";
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 2);
  EXPECT_EQ(tree, nullptr);
}

TEST (StringTest, InvalidEnd)
{
  char* test_val[2]; test_val[0] = "3"; test_val[1] = "*"; 
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 2);
  EXPECT_EQ(tree, nullptr);
}

TEST (StringTest, InvalidDouble)
{
  char* test_val[3]; test_val[0] = "3"; test_val[1] = "/"; test_val[2] = "+"; 
  Factory* parser = new Factory();
  Base* tree = nullptr;
  tree = parser->parse(test_val, 3);
  EXPECT_EQ(tree, nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
