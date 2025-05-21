#include <iostream>
#include "raylib.h"


int main(int argc, char* argv[]) {
  InitWindow(200, 200, "Snake Game"); 

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello world", 50,50,20,LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
