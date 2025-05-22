#include <iostream>
#include "raylib.h"
#include "snake.h"
#include "fruit.h"



struct Color SNAKE_GREEN = {173,204,96,255};
  
int main(int argc, char* argv[]) {
  InitWindow(30 * 25, 30 * 25, "Snake Game"); 
  Snake snake;
  Fruit apple;

  while (!WindowShouldClose()) {
    
    snake.move();

    BeginDrawing();
    //To show the fps
    DrawFPS(10,10);
    ClearBackground(SNAKE_GREEN);

    //these two function handles the graphic of each texture  
    snake.draw();
    apple.draw();

    EndDrawing();
  }

  CloseWindow();


  return EXIT_SUCCESS;
}
