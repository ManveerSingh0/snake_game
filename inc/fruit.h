#ifndef FRUIT_H
#define FRUIT_H

#include "raylib.h"

class Fruit {
public:
  Fruit();
  void draw();
  Rectangle food_rec;


  ~Fruit();

private:
  Texture2D apple;



};


#endif //FRUIT_H
