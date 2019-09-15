// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <thread>
#include <Player.hpp>
#include <Mode.hpp>
#include <IntroMode.hpp>
#include <MenuMode.hpp>
#include <GameMode.hpp>
#include <RuntimeStats.hpp>
// Entry Point
int main() {
	// Setup Window
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	window.setActive(false);
	// Prepare Screen Elements
	std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>screenElements;
	// Prepare Stack
	std::stack<Mode*> ModeStack;
	ModeStack.push(new IntroMode(&screenElements));

	// Create Rendering Thread
	std::thread RenderThread([&window, &screenElements] {
		// Window Settings
		window.setActive(true);
		window.setFramerateLimit(5000);
		// Setup Stats
		RuntimeStats stats;
		// Render Loop
		while (true) {
			// Rendering
			window.clear();
			for (const auto& element : screenElements) {
				window.draw(*element.first);
			}
			stats.draw(window);
			window.display();
			stats.update();
		}
	});

	// Begin Game
	sf::Clock GameClock;
	while (!ModeStack.empty()) {
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
				ModeStack.push(new IntroMode(&screenElements));
				break;
			case ModeOption::Menu:
				ModeStack.push(new MenuMode(&screenElements));
				break;
			case ModeOption::Game:
				ModeStack.push(new GameMode(&screenElements));
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
	RenderThread.join();
	window.close();
}
