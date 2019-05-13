// Proprocessor
#include <SFML/Graphics.hpp> // SFML Graphics
#include <iostream> // IO
#include <iomanip> // IO Manipulation
#include <string> // String
#include <experimental/filesystem> // FilePath
namespace filesystem = std::experimental::filesystem::v1; // FilePath
#include "player.h" // Player Class
// Entry Point
int main() {
	//***************
	// Window Setup *
	//***************
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Cnake", sf::Style::Close | sf::Style::Titlebar); // Create Window
	Player player; // Create player object
	player.setColor(sf::Color::Cyan, sf::Color::Red); // Color in snake
	player.setPosition(); // Center Snake
	sf::RectangleShape * snake = player.access(); // Ptr to snake of player

	//************
	// Game Loop *
	//************
	sf::Clock gameClock; // Begin and create game clock
	sf::Time tick = sf::milliseconds(200); // Divide game into 4 parts per second ticks
	while (window.isOpen()) { 
		//*****************
		// Event Handeler *
		//*****************
		sf::Event evnt;
		while (window.pollEvent(evnt)) { // Poll for events, if no event then skip 
			switch (evnt.type)
			{
			case sf::Event::Closed: 
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New window size (" << evnt.size.width << ", " << evnt.size.height << ")" << std::endl;
				break;
			//case sf::Event::TextEntered:
			//	if (evnt.text.unicode < 128) {
			//		std::cout << static_cast<char>(evnt.text.unicode) << '\n'; // Post key to console 
			//	}
			//	break;
			case sf::Event::KeyPressed: 
				switch (evnt.key.code) 
				{
				case sf::Keyboard::W:

				case sf::Keyboard::A:
				
				case sf::Keyboard::S:
				
				case sf::Keyboard::D:
					player.setDir(evnt.key.code); // Change Direction of snake
					break;
				case sf::Keyboard::Escape: // ESC Pressed
					window.close(); // Close Window
					break;
				}
			}
		}
		sf::Time elapsed = gameClock.getElapsedTime(); // Grab time elapsed 
		//std::cout << elapsed.asSeconds();
		if ((elapsed > tick) && (player.getDir() != STOP)) {
			player.move(); // Move the player along the screen
			gameClock.restart();
		}

		window.clear();
		window.draw(snake[0]);
		window.draw(snake[1]);
		window.draw(snake[2]);
		window.display();

	}
}

