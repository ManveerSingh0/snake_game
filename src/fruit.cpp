#include "fruit.h"
#include "raylib.h"


Fruit::Fruit() {
  apple = LoadTexture("../assets/apple.png");
}

void Fruit::draw() {
  food_rec = {40,40,30,30};
  DrawTexture(apple, static_cast<int>(food_rec.x), static_cast<int>(food_rec.y), WHITE);
}



Fruit::~Fruit() {
  UnloadTexture(apple);
}
