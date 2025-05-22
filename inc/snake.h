#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include "fruit.h"

#include <deque>

class Snake {
public: //functions and constructors
  Snake();
  void move(Fruit&,float,float);
  void draw();
  void increase_size(Fruit&, float, float);

private: // functions and constructors



public: //variable 
  struct Rectangle snake;
  std::deque<Rectangle> segments;

private:
  Vector2 direction;
  float x_value;
  float y_value;
  float move_timer;
  float move_interval;
};



#endif //SNAKE_H
