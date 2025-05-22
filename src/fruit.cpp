#include "fruit.h"
#include "raylib.h"


Fruit::Fruit() {
  apple = LoadTexture("../assets/apple.png");
}

void Fruit::draw() {
  DrawTexture(apple,40,40,WHITE);
}
