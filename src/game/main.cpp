#include <iostream>
#include "raylib.h"


struct Color red = {255,0,0,255};


int main(int argc, char* argv[]) {
  InitWindow(200, 200, "Snake Game"); 
  SetTargetFPS(60);


  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello world", 50,50,20,LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
