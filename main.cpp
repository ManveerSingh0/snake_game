//SFML specific libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window.hpp>

//cpp std libraries
#include <iostream>


int main(){
  sf::RenderWindow window(sf::VideoMode(sf::Vector2u({500, 500})), "Main Window");
  sf::Texture character;
  if (!character.loadFromFile("../assets/character_beige_front.png")) {
    std::cout << "character isn't loaded\n";
  }
  character.setSmooth(true);

  auto textureSize = character.getSize();
  sf::Sprite sprite(character);
  const float desiredWidth = 50.0f;
  const float desiredHeight = 50.0f;
  float scaleX = desiredWidth / textureSize.x;
  float scaleY = desiredHeight / textureSize.y;
  sprite.setScale({scaleX, scaleY});

  while (window.isOpen()) {
    
    //This is another way to close the window
    // window.handleEvents(
    // 			[&window](const sf::Event::Closed){
    // 			  std::cout << "Event Closed\n";
    // 			  window.close();
    // 			}
    //     );
   while (std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is < sf::Event::Closed>()) {
	window.close();
      } else if (const sf::Event::KeyPressed *key_pressed =
		 event->getIf<sf::Event::KeyPressed>()) {
        if (key_pressed->scancode == sf::Keyboard::Scancode::Escape) {
	  window.close();
        }
      } else if (const sf::Event::Resized *resize =
                     event->getIf<sf::Event::Resized>()) {
	std::cout << "width: " << resize->size.x << '\n';
	std::cout << "height: " << resize->size.y << '\n';
      } else if (const sf::Event::FocusLost *focus =
                     event->getIf<sf::Event::FocusLost>()) {
	std::cout << "focust lost\n";
      }else if (const sf::Event::FocusGained *focus =
                     event->getIf<sf::Event::FocusGained>()) {
	std::cout << "focust Gained\n";
      }
   }

   window.clear();
   window.draw(sprite);
   window.display();
  }

}
