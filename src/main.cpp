// Proprocessor
#include <SFML/Graphics.hpp> // SFML Graphics
#include <iostream> // IO
#include <iomanip> // IO Manipulation
#include <string> // String
#include <filesystem> // FilePath
#include "player.h" // Player Class
// Entry Point
int main() {
	//***************
	// Window Setup *
	//***************
	//sf::Font bauh; // Create bauh local font
	//if (!bauh.loadFromFile("../fonts/BAUHS93.TTF")) { // Load bauh from file
	//  std::cout << "Error loading font BAUHS93" << std::endl; // Output if error
	//}

  unsigned int sHeight = 900, sWidth = 1600; // Create reusable values of window width and height
	sf::RenderWindow window(sf::VideoMode(sWidth, sHeight), "Cnake", sf::Style::Close | sf::Style::Titlebar); // Create Window
	Player player; // Create player object
	player.setColor(sf::Color::Cyan, sf::Color::Red); // Color in snake
	player.setPosition(); // Center Snake
	
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

	/*std::string scoreString = "Score :" + player.getScore();
	std::cout << scoreString << std::endl;
	sf::Text scoreText(scoreString, sf::Font(bauh), 30);
	scoreText.setPosition((sWidth / 10), (sHeight / 10));
	scoreText.setColor(sf::Color::Black);
	scoreText.setOutlineColor(sf::Color::White);
	scoreText.setOutlineThickness(2);*/

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
		window.draw(background);
		window.draw(playArea);
		player.drawSnake(window);
		/*window.draw(scoreText);*/
		window.display();

	}
}
