#include "snake.h"
#include "raylib.h"



Snake::Snake() {
  direction = {1,0};
  segments = {{100,100,20,20},{80,100,20,20},{60,100,20,20}};


  move_timer = 0.0f;
  move_interval = 0.1f;
}


void Snake::move(const Fruit& fruit) {
  float delta = GetFrameTime();
  float speed = 100.0f; // 100 pixels/second
  move_timer += delta;




  if (IsKeyDown(KEY_D) && direction.x != -1) { // Right, not if moving left
    direction = {1, 0};
  } else if (IsKeyDown(KEY_A) && direction.x != 1) { // Left, not if moving right
    direction = {-1, 0};
  } else if (IsKeyDown(KEY_W) && direction.y != 1) { // Up, not if moving down
    direction = {0, -1};
  } else if (IsKeyDown(KEY_S) && direction.y != -1) { // Down, not if moving up
    direction = {0, 1};
  }



  if (move_timer >= move_interval) {
    increase_size(fruit);
    move_timer -= move_interval; 
  } 

}

void Snake::draw() {

  for (int i = 0; i < segments.size(); i++) {
    DrawRectangleRounded(segments.at(i), 0.2f, 8, DARKGRAY);
  }

}

void Snake::increase_size(const Fruit& fruit) {
  if (fruit.food_rec.x == segments[0].x && fruit.food_rec.y == segments[0].y) {
    x_value = segments[0].x + direction.x * 20;
    y_value = segments[0].y + direction.y * 20;
    struct Rectangle new_head = {x_value, y_value, 20, 20};
    segments.push_front(new_head);
    snake = segments[0];
  } else {
    x_value = segments[0].x + direction.x * 20;
    y_value = segments[0].y + direction.y * 20;
    struct Rectangle new_head = {x_value, y_value, 20, 20};
    segments.push_front(new_head);
    segments.pop_back();
    snake = segments[0];    
  }
}
