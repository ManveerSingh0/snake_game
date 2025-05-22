#include "fruit.h"
#include "raylib.h"


Fruit::Fruit() {
  apple = LoadTexture("../assets/apple.png");
  food_rec = {40,40,30,30};
}

void Fruit::draw() {

  DrawTexture(apple, static_cast<int>(food_rec.x), static_cast<int>(food_rec.y), WHITE);
}



Fruit::~Fruit() {
  UnloadTexture(apple);
}
