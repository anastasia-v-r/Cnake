// Proprocessor
#include <SFML/Graphics.hpp> // SFML Graphics
#include <iostream> // IO
#include <string> // String
#include <experimental/filesystem> // FilePath
namespace filesystem = std::experimental::filesystem::v1; // FilePath
#include "player.h" // Player Class
// Entry Point
int main() {
	// Window Setup
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Cnake", sf::Style::Close | sf::Style::Titlebar); // Create Window
	player player;
	

	while (window.isOpen()) { // Game Loop

		sf::Event evnt;
		while (window.pollEvent(evnt)) { // Check all events since last iteration
			switch (evnt.type) { 
			
			case sf::Event::Closed: 
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New window size (" << evnt.size.width << ", " << evnt.size.height << ")" << std::endl;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					std::cout << static_cast<char>(evnt.text.unicode) << '\n';
				}
			}
		}
		
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.25f);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.25f, 0.0f);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.25f);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.25f, 0.0f);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mosPos = sf::Mouse::getPosition(window);
			player.setPosition((float)mosPos.x, (float)mosPos.y);
		}*/

		window.clear();
		window.display();

	}
}

