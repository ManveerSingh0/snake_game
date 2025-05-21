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


  // Today learn about this , what is scaling and how does it works
  auto textureSize = character.getSize();
  sf::Sprite character_sprite(character);
  const float desiredWidth = 50.0f;
  const float desiredHeight = 50.0f;
  float scaleX = desiredWidth / textureSize.x;
  float scaleY = desiredHeight / textureSize.y;
  character_sprite.setScale({scaleX, scaleY});
  character_sprite.setPosition(sf::Vector2f{0.0f,450.0f});

  sf::Vertex vertex;
  vertex.position = sf::Vector2f(10.0f, 50.0f);
  vertex.color = sf::Color::Red;
  vertex.texCoords = sf::Vector2f(100.f,100.f);
  // create an array of 3 vertices that define a triangle primitive
sf::VertexArray triangle(sf::PrimitiveType::Triangles, 3);

// define the position of the triangle's points
triangle[0].position = sf::Vector2f(10.f, 10.f);
triangle[1].position = sf::Vector2f(100.f, 10.f);
triangle[2].position = sf::Vector2f(100.f, 100.f);

// define the color of the triangle's points
triangle[0].color = sf::Color::Red;
triangle[1].color = sf::Color::Blue;
triangle[2].color = sf::Color::Green;



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
	  character_sprite.move({10.0f,10.0f});
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
   window.draw(character_sprite);
   window.draw(triangle);
   window.display();
  }
}
