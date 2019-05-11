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
	Player player; // Create player object
	player.setColor(sf::Color::Cyan, sf::Color::Red); // Color in snake
	player.setPosition(); // Center Snake
	sf::RectangleShape * snake = player.access(); // Ptr to snake of player
	sf::Vector2f tempV2F;

	//sf::Texture playertexture; // Create a texture for player
	//playertexture.loadFromFile("../textures/snakeblock.png"); // Grab texture
	//player.(&playertexture); // Load texture into Player

	while (window.isOpen()) { // Game Loop

		sf::Event evnt;
		while (window.pollEvent(evnt)) { // Check all events since last iteration
			switch (evnt.type) { 
			
			case sf::Event::Closed: 
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New window size (" << evnt.size.width << ", " << evnt.size.height << ")" << std::endl;
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					std::cout << static_cast<char>(evnt.text.unicode) << '\n';
				}
				break;
			case sf::Event::KeyPressed:
				player.move(evnt.key.code);
				tempV2F = snake[0].getPosition();
				float v2fX = tempV2F.x; float v2fY = tempV2F.y;
				std::cout << v2fX << ", " << v2fY << std::endl;
			}
		}

		window.clear();
		window.draw(snake[0]);
		window.draw(snake[1]);
		window.draw(snake[2]);
		window.display();

	}
}

