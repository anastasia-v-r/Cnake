// Proprocessor
#include <SFML/Graphics.hpp> // SFML Graphics
#include <SFML/Window.hpp> // SFML Window
#include <SFML/System.hpp> // SFML System
#include <iostream> // IO
#include <sstream> // String Stream
#include <iomanip> // IO Manipulation
#include <string> // String
#include <fstream> // File I/O
#include "fs.hpp" // FilePath
#include "player.h" // Player Class
// Entry Point
int main() {
	//***************
	// Window Setup *
	//***************
	#ifdef FS_SUPPORT
	std::cout << std::filesystem::current_path().string() << std::endl;
	#endif
	unsigned int sHeight = 900, sWidth = 1600; // Create reusable values of window width and height
	sf::RenderWindow window(sf::VideoMode(sWidth, sHeight), "Cnake", sf::Style::Close | sf::Style::Titlebar); // Create Window
	Player player; // Create player object
	player.setColor(sf::Color::Cyan, sf::Color::Red); // Color in snake
	player.setPosition(); // Center Snake
	
	std::cout << player.getScore() << std::endl;

	sf::RectangleShape background(sf::Vector2f(sWidth, sHeight)); // Create Background
	background.setFillColor(sf::Color(255, 255, 255, 50)); // Make it dark grey
	background.setOrigin(background.getSize().x / 2, background.getSize().y / 2); // Center the Origin
	background.setPosition(sWidth / 2, sHeight / 2); // Center the Position

	sf::RectangleShape playArea(sf::Vector2f(sWidth - 10, sHeight - 10)); // Create overlay
	playArea.setFillColor(sf::Color::Transparent); // Make it hollow
	playArea.setOutlineThickness(10.0f); // Add border
	playArea.setOutlineColor(sf::Color(255, 255, 255, 130)); // Make border light grey
	playArea.setOrigin(playArea.getSize().x / 2, playArea.getSize().y / 2); // Center the Origin
	playArea.setPosition(sWidth / 2, sHeight / 2); // Center the Position

	sf::Font bauh; // Create bauh local font
	if (!bauh.loadFromFile("../../../fonts/bauh.ttf")) {
		std::cout << "Moving to second Directory" << std::endl;
		if (!bauh.loadFromFile("../fonts/bauh.ttf")) {
			std::cout << "Moving to second Directory" << std::endl;
			if (!bauh.loadFromFile("fonts/bauh.ttf")) {
				std::cout << "All directories exhausted for font bauh" << std::endl;
			}
		}
	}
	std::stringstream ss;
	ss << "Score : " << player.getScore();
	sf::Text scoreText(sf::String(ss.str()), bauh, 30);
	scoreText.setOrigin(scoreText.getScale().x / 2, scoreText.getScale().y / 2);
	scoreText.setPosition(sWidth / 50, (sHeight / 10) * 9);
	scoreText.setColor(sf::Color::Red);

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
		window.draw(background); // Draw BG
		window.draw(playArea); // Draw Play Box over that
		player.drawSnake(window); // Draw Snake over that
		window.draw(scoreText); // Draw score overlay
		window.display();

	}
}
