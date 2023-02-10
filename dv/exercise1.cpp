#include <catch2/catch_test_macros.hpp>
#include <VExercise1.h>

TEST_CASE("Exercise 1") {
  VExercise1 model;
  bool wrong = false;
  for (model.op = 0; model.op < 4; model.op ++){
    for (model.a = 0; model.a < 256; model.a ++){
      for (model.b = 0; model.b < 256; model.b ++){
        model.eval();
        if(model.op == 0) {
          if((model.a ^ model.b) != model.out) wrong = true;}
        if(model.op == 1) {
          if((model.a << model.b) != model.out) wrong = true;}
        if(model.op == 2) {
          if(model.b != 0){
          if((model.a % model.b) != model.out) wrong = true;}}
        if(model.op == 0) {
          if((~(model.a & model.b)) != model.out) wrong = true;}
      }
    }
  }
  REQUIRE(wrong == false)
}
