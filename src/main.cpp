// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include "fs.hpp" 
#include "player.hpp"
#include "Mode.hpp"
#include "IntroMode.hpp"
#include "MenuMode.hpp"
#include "GameMode.hpp"
// Func
void RenderScreen(sf::RenderWindow* window) {
	window->setActive(true);
	sf::Clock RenderClock;
	unsigned int frames = 0;
	unsigned int FPS = 0;
	sf::Font font;
	font.loadFromFile("../../../fonts/bauh.ttf");
	std::cout << "yah";
	sf::Text FPSText(frames, font, 30);
	while (true) {
		window->clear();
		window->draw(FPSText);
		window->display();
		frames++;
		FPS = frames / RenderClock.getElapsedTime().asSeconds();
		FPSText.setString(std::to_string(FPS));
	}
}
// Entry Point
int main() {
	// Path Check
	#ifdef FS_SUPPORT
		std::cout << fs::current_path().string() << std::endl;
	#endif
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	window.setActive(false);

	std::vector<sf::RectangleShape> Elements{sf::RectangleShape(sf::Vector2f(10, 10))};
	std::stack<Mode*> ModeStack;
	ModeStack.push(new IntroMode);

	sf::Thread RenderThread(&RenderScreen, &window);
	RenderThread.launch();

	sf::Clock GameClock;
	while (window.isOpen()) {
		sf::Time timePassed = GameClock.restart();
		auto result = ModeStack.top()->Run(timePassed, window);
		switch (result.first)
		{
		case ModeAction::None:
			break;
		case ModeAction::Add:
			switch (result.second)
			{
			case ModeOption::Intro:
				ModeStack.push(new IntroMode);
				break;
			case ModeOption::Menu:
				ModeStack.push(new MenuMode);
				break;
			case ModeOption::Game:
				ModeStack.push(new GameMode);
				break;
			case ModeOption::Paused:
				// TODO: Decide how to pause the game
				break;
			}
			break;
		case ModeAction::Remove:
			ModeStack.pop();
			break;
		}
	}


}
