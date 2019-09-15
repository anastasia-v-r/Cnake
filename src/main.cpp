// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include "fs.hpp" 
#include "player.hpp"
#include "Mode.hpp"
#include "IntroMode.hpp"
#include "MenuMode.hpp"
#include "GameMode.hpp"
// Func
void RenderScreen(std::pair<sf::RenderWindow*, std::vector<sf::RectangleShape*>> pair) {
	sf::RenderWindow* window = pair.first;
	std::vector<sf::RectangleShape*> screenElements = pair.second;
	window->setActive(true);
	// window->setFramerateLimit(120);
	sf::Clock RenderClock;
	unsigned int totalFrames = 0;
	sf::Time totalTime(sf::Time::Zero);
	sf::Time elapsedTime(sf::Time::Zero);
	sf::Font font;
	font.loadFromFile("../../../fonts/bauh.ttf");
	sf::Text FPSCounter("", font, 30);
	sf::Text FrameInterval("", font, 15);
	FrameInterval.move(0, 30);

	sf::Texture boxTexture;
	boxTexture.loadFromFile("../../../textures/snakebody.png");
	sf::RectangleShape box(sf::Vector2f(100, 100));
	box.setTexture(&boxTexture);
	box.move(500, 500);

	while (true) {
		// Rendering
		window->clear();
		for (const auto& element : screenElements) {
			window->draw(*element);
		}
		window->draw(FPSCounter);
		window->draw(FrameInterval);
		window->display();
		// Stat Updates
		elapsedTime = RenderClock.restart();
		totalTime += elapsedTime;
		totalFrames += 1;
		FPSCounter.setString(std::to_string(static_cast<unsigned int>(totalFrames / totalTime.asSeconds())) + " FPS");
		FrameInterval.setString(std::to_string(totalTime.asMicroseconds() / totalFrames) + "µs FrameTime");
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

	sf::Thread RenderThread(&RenderScreen, std::make_pair(&window, &Elements));
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
