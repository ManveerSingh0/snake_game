#include "snake.h"
#include "raylib.h"



Snake::Snake() {
  snake =  {100,100,20,20};
  direction = {1,0};
}


void Snake::move() {
    float delta = GetFrameTime();
    float speed = 100.0f; // 100 pixels/second

    // Check for key presses to change direction
    // Prevent reversing directly (e.g., right to left)
    if (snake.x < 0) {
      snake.x = GetScreenWidth();
    }
    if (snake.x > GetScreenWidth()) {
      snake.x = 0;
    }
    if (snake.y > GetScreenHeight()) {
      snake.y = 0;
    }
    if (snake.y < 0) {
      snake.y = GetScreenHeight();
    }



    if (IsKeyDown(KEY_D) && direction.x != -1) { // Right, not if moving left
        direction = {1, 0};
    } else if (IsKeyDown(KEY_A) && direction.x != 1) { // Left, not if moving right
        direction = {-1, 0};
    } else if (IsKeyDown(KEY_W) && direction.y != 1) { // Up, not if moving down
        direction = {0, -1};
    } else if (IsKeyDown(KEY_S) && direction.y != -1) { // Down, not if moving up
        direction = {0, 1};
    }

    // Move continuously in the current direction
    snake.x += direction.x * speed * delta;
    snake.y += direction.y * speed * delta;
}

void Snake::draw() {
  DrawRectangleRounded(snake, 0.2f, 1, DARKGRAY);
}
