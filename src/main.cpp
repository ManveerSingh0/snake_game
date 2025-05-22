#include "raylib.h"
#include "snake.h"
#include "fruit.h"

#include <random>



struct Color SNAKE_GREEN = {173,204,96,255};
  
int main(int argc, char* argv[]) {
  InitWindow(30 * 25, 30 * 25, "Snake Game"); 
  Snake snake;
  Fruit apple;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 29); // 0 to 29 for 30x30 grid



  while (!WindowShouldClose()) {
    
    snake.move(apple, distrib(gen) * 20.0f, distrib(gen) * 20.0f);

    BeginDrawing();
    //To show the fps
    DrawFPS(10,10);

    ClearBackground(SNAKE_GREEN);
    //these two function handles the graphic of each texture  
    snake.draw();
    apple.draw();

    DrawText(TextFormat("Score: %d", snake.score), 300,10,30,WHITE);
    EndDrawing();
  }

  CloseWindow();


  return 0;
}
