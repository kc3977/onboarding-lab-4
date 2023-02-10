#include <catch2/catch_test_macros.hpp>
#include <VExercise3.h>

TEST_CASE("Exercise 3") {
  VExercise3 model;
  bool wrong = false;
  //testing mystery1's
  model.b = 0b1111111111111111;
  model.c = 0b0000000000000000;
  model.a = 0b0000;
  model.eval();
  if (model.a_in != 0b00111000) wrong = true;
  if (model.b_in != 0b00111000) wrong = true;
  model.a = 0b0001;
  model.eval();
  if (model.a_in != 0b00000111) wrong = true;
  if (model.b_in != 0b00111000) wrong = true;
  model.a = 0b0110;
  model.eval();
  if (model.a_in != 0b11111111) wrong = true;
  if (model.b_in != 0b00000111) wrong = true;
  model.a = 0b1111;
  model.eval();
  if (model.a_in != 0b00000000) wrong = true;
  if (model.b_in != 0b00000000) wrong = true;
  model.a = 0b1011;
  model.eval();
  if (model.a_in != 0b00000000) wrong = true;
  if (model.b_in != 0b11111111) wrong = true;
 
  //testing mystery2's
  model.reset = 1;
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
  if (model.out != 0b1111111100000000) wrong = true;
  
  for (int i =0; i < 5; i++){
    uint16_t prev_out = model.out;
    model.reset = 0;
    model.eval();
    model.clk = 1;
    model.eval();
    model.clk = 0;
    model.eval();
    
    if (i == 0) {
    if (model.out != 0b0000000000000000) wrong = true;}
    if (i == 1) {
    if (model.out != 0b0000000011111111) wrong = true;}
    if (i == 2) {
    if (model.out != 0b1111111100000000) wrong = true;}
    if (i == 3) {
    if (model.out != 0b0000000011111111) wrong = true;}
    if (i == 4) {
    if (model.out != 0b0000000000000000 | (0b0000000000000001 &(^prev_out))) wrong = true;}
  }
  REQUIRE(wrong == false)
}
