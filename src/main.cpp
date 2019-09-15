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
void RenderScreen(sf::RenderWindow& window, std::vector<sf::RectangleShape>& screenElements) {
	// Window Settings
	window.setActive(true);
	window.setFramerateLimit(5000);
	// Stat Holders
	sf::Clock RenderClock;
	unsigned int totalFrames = 0;
	sf::Time totalTime(sf::Time::Zero);
	sf::Time elapsedTime(sf::Time::Zero);
	// Text Setup
	sf::Font font;
	font.loadFromFile("../../../fonts/bauh.ttf");
	sf::Text FPSCounter("", font, 30);
	sf::Text FrameInterval("", font, 15);
	FrameInterval.move(0, 30);
	// Render Loop
	while (true) {
		// Rendering
		window.clear();
		for (const auto& element : screenElements) {
			window.draw(element);
		}
		window.draw(FPSCounter);
		window.draw(FrameInterval);
		window.display();
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

	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	window.setActive(false);

	std::vector<sf::RectangleShape> Elements{sf::RectangleShape(sf::Vector2f(10, 10))};
	Elements[0].move(500, 500);

	std::stack<Mode*> ModeStack;
	ModeStack.push(new IntroMode);

	std::thread RenderThread(RenderScreen, std::ref(window), std::ref(Elements));

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
