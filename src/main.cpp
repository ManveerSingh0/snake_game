#include <iostream>
#include "raylib.h"
#include "snake.h"

struct Color SNAKE_GREEN = {173,204,96,255};
  
int main(int argc, char* argv[]) {
  InitWindow(30 * 25, 30 * 25, "Snake Game"); 
  Snake snake;


  int frame_count = 0;
  float time_elapsed = 0.0f;
  int fps = 0;
  const float update_interval = 1.0f;
  
  while (!WindowShouldClose()) {
    float delta = GetFrameTime();
    time_elapsed += delta;
    frame_count++;

    if (time_elapsed >= update_interval) {
      fps = static_cast<int>(frame_count / time_elapsed);
      time_elapsed = 0.0f;
      frame_count = 0;
    }

    snake.move();

    BeginDrawing();
  
    ClearBackground(SNAKE_GREEN);
    snake.draw();
    DrawText(TextFormat("FPS: %d", fps), 10, 10, 20 , BLACK);
    EndDrawing();
  }

  CloseWindow();


  return EXIT_SUCCESS;
}
