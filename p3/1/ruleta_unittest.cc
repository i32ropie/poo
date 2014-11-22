// ruleta_unittest.cc: Eduardo Roldan Pijuan
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h"
#include "gtest/gtest.h"


TEST(Ruleta, PruebaRuleta1)
{
   Crupier c("33XX","2A");
   Ruleta r(c);
   EXPECT_EQ(1000000,r.getBanca());
}