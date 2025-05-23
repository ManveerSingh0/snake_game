#include "snake.h"
#include "raylib.h"



Snake::Snake() {
  direction = {1,0};
  segments = {{100,100,20,20},{80,100,20,20},{60,100,20,20}};


  move_timer = 0.0f;
  move_interval = 0.1f;

  min_move_interval = 0.001f;
  last_score_threshold = 0;

}


void Snake::move(Fruit& fruit, float x , float y) {
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



  for (int i = 1; i < segments.size(); i++) {
    if (CheckCollisionRecs(segments[0], segments[i])) {
      CloseWindow();
    }
  }

  if (move_timer >= move_interval) {
    increase_size(fruit, x,y);
    move_timer -= move_interval; 
  }


  out_of_bound();

}

void Snake::draw() {

  for (int i = 0; i < segments.size(); i++) {
    DrawRectangleRounded(segments.at(i), 0.2f, 8, DARKGRAY);
  }

}

void Snake::increase_size(Fruit& fruit, float x, float y) {
  if (CheckCollisionRecs(snake, fruit.food_rec)) {
    x_value = segments[0].x + direction.x * 20;
    y_value = segments[0].y + direction.y * 20;

    
    struct Rectangle new_head = {x_value, y_value, 20, 20};
    segments.push_front(new_head);
    snake = segments[0];


    fruit.food_rec.x = x;
    fruit.food_rec.y = y;

    score += 1;
    if(score % 10 == 0 && score > last_score_threshold){
      move_interval -= 0.01f;
      if(move_interval < min_move_interval){
        move_interval = min_move_interval;
      }
      last_score_threshold = score;
    }
  } else {
    x_value = segments[0].x + direction.x * 20;
    y_value = segments[0].y + direction.y * 20;
    struct Rectangle new_head = {x_value, y_value, 20, 20};
    segments.push_front(new_head);
    segments.pop_back();
    snake = segments[0];
  }
}



void Snake::out_of_bound() {
  if (snake.x > GetScreenWidth()) {
    segments[0].x = 0;
  } else if (snake.x < 0) {
    segments[0].x = GetScreenWidth();
  }



  if (snake.y > GetScreenHeight()) {
    segments[0].y = 0;
  } else if (snake.y < 0) {
    segments[0].y = GetScreenHeight();    
  }
}
