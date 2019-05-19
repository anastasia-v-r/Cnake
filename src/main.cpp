// Proprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include "fs.hpp" 
#include "player.h" 
#include "screen.h"
// Entry Point
int main() {
	// Path Check
	#ifdef FS_SUPPORT
		std::cout << fs::current_path().string() << std::endl;
	#endif

	auto desktop = sf::VideoMode::getDesktopMode();
	unsigned int sWidth = static_cast<unsigned int>(desktop.width), sHeight = static_cast<unsigned int>(desktop.height);
	sf::RenderWindow window(sf::VideoMode(sWidth + 1, sHeight, desktop.bitsPerPixel), "Cnake", sf::Style::None);
	Screen screenBuffer();
	
	Player playerSnake; 
	playerSnake.setColor(sf::Color::Cyan, sf::Color::Red); 
	playerSnake.setPosition(sWidth, sHeight); 

	sf::RectangleShape background(sf::Vector2f(sWidth, sHeight)); 
	background.setFillColor(sf::Color(255, 255, 255, 50)); 
	background.setOrigin(background.getSize().x / 2, background.getSize().y / 2); 
	background.setPosition(sWidth / 2, sHeight / 2); 

	sf::RectangleShape playBox(sf::Vector2f(sWidth - playerSnake.getSize().x, sHeight - playerSnake.getSize().x)); 
	playBox.setFillColor(sf::Color::Transparent); 
	playBox.setOutlineThickness(10.0f); 
	playBox.setOutlineColor(sf::Color(255, 255, 255, 130)); 
	playBox.setOrigin(playBox.getSize().x / 2, playBox.getSize().y / 2); 
	playBox.setPosition(sWidth / 2, sHeight / 2);  

	sf::Font bauh; 
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
	ss << "Score : " << playerSnake.getScore();
	sf::Text scoreText(sf::String(ss.str()), bauh, 30);
	scoreText.setOrigin(scoreText.getScale().x / 2, scoreText.getScale().y / 2);
	scoreText.setPosition(sWidth / 50, (sHeight / 10) * 9);
	scoreText.setColor(sf::Color::Red);

	sf::Clock gameClock; 
	sf::Time tick = sf::milliseconds(200); 

	bool gamePaused = false;
	while (window.isOpen()) {

		sf::Event evnt;
		while (window.pollEvent(evnt)) { 
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus:

			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					char keyOut = static_cast<char>(evnt.text.unicode);
					std::cout << "Keypressed : [" << keyOut << "]" << std::endl;  
				}
				break;
			case sf::Event::KeyPressed:
				if (!gamePaused) {
					switch (evnt.key.code)
					{
					case sf::Keyboard::W:
					case sf::Keyboard::A:
					case sf::Keyboard::S:
					case sf::Keyboard::D:
						playerSnake.setDir(evnt.key.code); 
						break;
					case sf::Keyboard::Escape: 
						gamePaused = !gamePaused;
						break;
					}
				} else {
					switch (evnt.key.code)
					{
					case sf::Keyboard::W:
					case sf::Keyboard::Up:
					case sf::Keyboard::S:
					case sf::Keyboard::Down:
						
						break;
					case sf::Keyboard::Enter:

						break;
					}
				}
			}
		}

		if (!gamePaused) {
			sf::Time elapsed = gameClock.getElapsedTime(); 
			if ((elapsed > tick) && (playerSnake.getDir() != STOP)) {
				playerSnake.move(); 
				gameClock.restart();
			}
		}

		window.clear();
		window.draw(screenObjects);
		window.display();
		// sprite.getGlobalBounds().contains(mousePos) // storing here for later
	}
}
