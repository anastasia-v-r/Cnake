// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <thread>
#include "fs.hpp" 
#include "player.hpp"
#include "Mode.hpp"
#include "IntroMode.hpp"
#include "MenuMode.hpp"
#include "GameMode.hpp"
// Func
void RenderScreen(sf::RenderWindow&, std::vector<sf::RectangleShape>&);
// Entry Point
int main() {
	// Path Check
	#ifdef FS_SUPPORT
		std::cout << fs::current_path().string() << std::endl;
	#endif
	
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1.0f;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);

	std::vector<sf::RectangleShape> Elements;
	std::stack<Mode*> ModeStack;
	
	while (window.isOpen()) {

	}


}
// Func
void RenderScreen(sf::RenderWindow& window, std::vector<sf::RectangleShape>& ScreenElements) {
	while (true) {
		window.clear();
		for (const auto& element : ScreenElements) {
			window.draw(element);
		}
		window.display();
	}
}