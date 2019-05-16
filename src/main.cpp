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
// #include "log.h"
#include "player.h" // Player Class
// Entry Point
int main() {
	// Path Check
	#ifdef FS_SUPPORT
	std::cout << fs::current_path().string() << std::endl;
	#endif
	//***************************************
	// Window Setup and Scren Element Setup *
	//***************************************
	auto desktop = sf::VideoMode::getDesktopMode(); // Grab the size of the monitor
	unsigned int sWidth = static_cast<unsigned int>(desktop.width), sHeight = static_cast<unsigned int>(desktop.height); // Create reusable values of window width and height
	sf::RenderWindow window(sf::VideoMode(sWidth + 1, sHeight, desktop.bitsPerPixel), "Cnake", sf::Style::None); // Create Window & add one to make borderless windowed
	//***************
	// Player Setup *
	//***************
	Player player; // Create player object
	player.setColor(sf::Color::Cyan, sf::Color::Red); // Color in snake
	player.setPosition(sWidth, sHeight); // Center Snake
	//*****************
	// Backdrop Setup *
	//*****************
	sf::RectangleShape background(sf::Vector2f(sWidth, sHeight)); // Create Background
	background.setFillColor(sf::Color(255, 255, 255, 50)); // Make it dark grey
	background.setOrigin(background.getSize().x / 2, background.getSize().y / 2); // Center the Origin
	background.setPosition(sWidth / 2, sHeight / 2); // Center the Position
	//****************
	// Playbox Setup *
	//****************
	sf::RectangleShape playBox(sf::Vector2f(sWidth - 10, sHeight - 10)); // Create overlay
	playBox.setFillColor(sf::Color::Transparent); // Make it hollow
	playBox.setOutlineThickness(10.0f); // Add border
	playBox.setOutlineColor(sf::Color(255, 255, 255, 130)); // Make border light grey
	playBox.setOrigin(playBox.getSize().x / 2, playBox.getSize().y / 2); // Center the Origin
	playBox.setPosition(sWidth / 2, sHeight / 2); // Center the Position  
	//*****************
	// Grab text font *
	//*****************
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
	//**********************
	// Score Tracker Setup *
	//**********************
	std::stringstream ss;
	ss << "Score : " << player.getScore();
	sf::Text scoreText(sf::String(ss.str()), bauh, 30);
	scoreText.setOrigin(scoreText.getScale().x / 2, scoreText.getScale().y / 2);
	scoreText.setPosition(sWidth / 50, (sHeight / 10) * 9);
	scoreText.setColor(sf::Color::Red);
	//*********************************
	// Game Clock and Time Management *
	//*********************************
	sf::Clock gameClock; // Begin and create game clock
	sf::Time tick = sf::milliseconds(200); // Divide game into 4 parts per second ticks
	//************
	// Game Loop *
	//************
	bool gamePaused = false;
	while (window.isOpen()) {
		//**********************************
		// User and Window Events Handeler *
		//**********************************
		sf::Event evnt;
		while (window.pollEvent(evnt)) { // Poll for events, if no event then skip 
			switch (evnt.type)
			{
			case sf::Event::Closed: 
				window.close();
				break;
			case sf::Event::LostFocus:
				
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					char keyOut = static_cast<char>(evnt.text.unicode);
					std::cout << "Keypressed : [" << keyOut << "]" << std::endl; // Post key to console 
					//logFile << "Keypressed : [" << keyOut << "]" << std::endl; // Post key to log
				}
				break;
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
					if (gamePaused) {
						gamePaused = false;
					} else {
						gamePaused = true;
					}
					break;
				}
			}
		}
		//**********************************
		// Game Logic and Updates Handeler *
		//**********************************
		if (!gamePaused) {
			sf::Time elapsed = gameClock.getElapsedTime(); // Grab time elapsed 
			if ((elapsed > tick) && (player.getDir() != STOP)) {
				player.move(); // Move the player along the screen
				gameClock.restart();
			}
		}
		//***********************
		// Game Drawing Handler *
		//***********************
		window.clear();
		window.draw(background); // Draw BG
		window.draw(playBox); // Draw Play Box over that
		player.drawSnake(window); // Draw Snake over that
		window.draw(scoreText); // Draw score overlay
		if (gamePaused) { // Overlay the pause Scren
			
		}
		window.display();
		// sprite.getGlobalBounds().contains(mousePos) // storing here for later
	}
}
