#include <catch2/catch_test_macros.hpp>
#include <VExercise4.h>

TEST_CASE("Exercise 4") {
  VExercise4 model;
  model.cs = 0;
  model.alpha = 0b11111111;
  model.beta = 0b11111111;
  model.gamma = 0b11111111;
  bool wrong = false;
  for (model.sel = 0; model.sel < 4; model.sel ++){
    model.eval();
    if (model.out != 0) wrong = true;
  }
  model.cs = 1;
  model.alpha = 0b11110000;
  model.beta = 0b00001111;
  model.gamma = 0b10101010;
  for (model.sel = 0; model.sel < 4; model.sel ++){
    model.eval();
    if (model.sel == 0){ 
      if(model.out != 0) wrong = true;}
    if (model.sel = 1){
      if(model.out != 0b11110000) wrong = true;}
    if (model.sel = 2){
      if(model.out != 0b00001111) wrong = true;}
    if (model.sel = 3){
      if(model.out != 0b11110000 & (0b00001111|0b10101010)) wrong = true;}
  }
  REQUIRE(wrong == false);
}
