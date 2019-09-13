// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string> 
#include "fs.hpp" 
#include "player.hpp"
#include "gameScreen.hpp"
#include "pauseScreen.hpp"
#include "startScreen.hpp"
// Data
enum GameState {
	INTRO = 0,
	PLAYING = 1,
	PAUSED = 2
};
// Entry Point
int main() {
	// Path Check
	#ifdef FS_SUPPORT
		std::cout << fs::current_path().string() << std::endl;
	#endif
	auto desktop = sf::VideoMode::getDesktopMode();
	unsigned int sWidth = static_cast<unsigned int>(desktop.width), sHeight = static_cast<unsigned int>(desktop.height);
	sf::RenderWindow window(sf::VideoMode(sWidth + 1, sHeight, desktop.bitsPerPixel), "Cnake", sf::Style::None);
	Player playerSnake(sf::Color::Blue, sf::Color::Green, sWidth, sHeight);
	GameState gameState(PLAYING);
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
				if (INTRO) {
					switch (evnt.key.code)
					{
					case sf::Keyboard::Enter:
						screenBuffer[0] = gameScreen;
						screenBuffer.reserve(screenBuffer.size() + 1);
						screenBuffer[1] = &playerSnake;
						gameState = PLAYING;
					}
				} else if (PLAYING) {
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
					case sf::Keyboard::Z:
						window.close();
						break;
					}
				}
			}
		}

		if (PLAYING) {
			sf::Time elapsed = gameClock.getElapsedTime(); 
			if ((elapsed > tick) && (playerSnake.getDir() != STOP)) {
				playerSnake.move(); 
				gameClock.restart();
			}
		}

		window.clear();
		for (const auto& screenElement : screenBuffer) {
			window.draw(*screenElement);
		}
		window.display();
		// sprite.getGlobalBounds().contains(mousePos) // storing here for later
	}
}
