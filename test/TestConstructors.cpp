#include <iostream>
#include <string.h>
#include "../src/Dvector.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Dvector, ConstruteurAvecParametres) {
  Dvector v = Dvector(5,2.0);
  EXPECT_EQ(5, v.size())
    << "Value does not equal the parameter.";
}

TEST(Dvector, ConstruteurSansParametres) {
  Dvector v = Dvector();
  EXPECT_EQ(0, v.size())
    << "Size not null";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
