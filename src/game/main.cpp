#include <SFML/Graphics.hpp>
#include "snake.h"



int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(sf::Vector2u{400,400}), "Snake Game");

  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
	window.close();
      }
    }

    window.clear();
    window.display();
  }



  return EXIT_SUCCESS;
}
