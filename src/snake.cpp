#include "snake.h"
#include "raylib.h"



Snake::Snake() {
  snake =  {20,20,20,20};
}


void Snake::move() {
  float delta = GetFrameTime();
  float speed = 100.0f;

  if (IsKeyDown(KEY_W)) {
    snake.y -= speed * delta;
  } else if (IsKeyDown(KEY_S)) {
    snake.y += speed * delta;
  } else if (IsKeyDown(KEY_D)) {
    snake.x += speed * delta;
  } else if (IsKeyDown(KEY_A)) {
    snake.x -= speed * delta;;
  }
}


void Snake::draw() {
  DrawRectangleRounded(snake, 0.2f, 1, DARKGRAY);
}
