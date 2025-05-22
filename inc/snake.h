#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>

class Snake {
public:
  Snake();
  void move();
  void draw();

private:
  struct Rectangle snake;
};



#endif //SNAKE_H
