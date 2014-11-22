// crupier_unittest.cc: Eduardo Roldan Pijuan
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
#include "crupier.h"
#include "gtest/gtest.h"

TEST(Crupier, ConstructorParametrosDefecto) {
  Crupier c("33XX","2A");
  
  EXPECT_EQ("33XX", c.getDNI());
  EXPECT_EQ("2A", c.getCodigo());
  EXPECT_EQ("", c.getNombre());
  EXPECT_EQ("", c.getApellidos());
  EXPECT_EQ("", c.getDireccion());
  EXPECT_EQ("", c.getLocalidad());
  EXPECT_EQ("", c.getProvincia());
  EXPECT_EQ("", c.getPais());
  EXPECT_EQ(", ", c.getApellidosyNombre());
}
 
TEST(Crupier, ConstructorParametros) {
  Crupier c("44XX", "1A","Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  
  EXPECT_EQ("44XX", c.getDNI());
  EXPECT_EQ("1A", c.getCodigo());
  EXPECT_EQ("Carlos", c.getNombre());
  EXPECT_EQ("Gutierrez", c.getApellidos());
  EXPECT_EQ("C/ Mesa 1", c.getDireccion());
  EXPECT_EQ("Aguilar", c.getLocalidad());
  EXPECT_EQ("Sevilla", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Gutierrez, Carlos", c.getApellidosyNombre());
}

TEST(Crupier, ConstructorCopiaDefecto) {
  Crupier c("44XX", "1A", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Crupier q(c);
  Crupier r=q;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("1A", q.getCodigo());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  
  EXPECT_EQ("44XX", r.getDNI());
  EXPECT_EQ("1A", r.getCodigo());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("España", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
}

TEST(Crupier, OperadorIgualDefecto) {
  Crupier c("44XX", "1A", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Crupier q("66FF", "2A");
  q=c;
  EXPECT_EQ("44XX", c.getDNI());
  EXPECT_EQ("1A", c.getCodigo());
  EXPECT_EQ("Carlos", c.getNombre());
  EXPECT_EQ("Gutierrez", c.getApellidos());
  EXPECT_EQ("C/ Mesa 1", c.getDireccion());
  EXPECT_EQ("Aguilar", c.getLocalidad());
  EXPECT_EQ("Sevilla", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Gutierrez, Carlos", c.getApellidosyNombre());
}
