#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>


int main(){
  sf::Window window(sf::VideoMode(sf::Vector2u({500, 500})), "Main Window");
  while (window.isOpen()) {
    while (std::optional event = window.pollEvent()) {
      if (event->is < sf::Event::Closed>()) {
	window.close();
      } else if (const auto *key_pressed =
                     event->getIf<sf::Event::KeyPressed>()) {
        if (key_pressed->scancode == sf::Keyboard::Scancode::Escape) {
	  window.close();
        }
      }
    }
  }

}
