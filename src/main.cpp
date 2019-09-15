// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <thread>
#include <mutex>
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
	std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* screenElements{ nullptr };
	// Prepare Stack
	std::stack<std::unique_ptr<Mode>> ModeStack;
	ModeStack.push(std::make_unique<IntroMode>());
	screenElements = &(ModeStack.top()->screenElements);
	// Variable for killing thread safely
	bool isRunning = true;
	// Create Rendering Thread
	// TODO: Create a threadsafe way to change the ptr to the top modes vector rather than simply copying an entire the entire vector and allow for use of `screenElements = &(ModeStack.top()->screenElements);`
	std::thread RenderThread([&window, &screenElements, &isRunning] {
		// Window Settings
		window.setActive(true);
		window.setFramerateLimit(5000);
		// Setup Stats
		RuntimeStats stats;
		// Render Loop
		while (isRunning) {
			// Rendering
			window.clear();
			for (const auto& element : (*screenElements)) {
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
				ModeStack.push(std::make_unique<IntroMode>());
				screenElements = &(ModeStack.top()->screenElements);
				break;
			case ModeOption::Menu:
				ModeStack.push(std::make_unique<MenuMode>());
				screenElements = &(ModeStack.top()->screenElements);
				break;
			case ModeOption::Game:
				ModeStack.push(std::make_unique<GameMode>());
				screenElements = &(ModeStack.top()->screenElements);
				break;
			case ModeOption::Paused:
				// TODO: Decide how to pause the game
				break;
			}
			break;
		case ModeAction::Remove:
			ModeStack.pop();
			if (ModeStack.empty()) {
				std::cout << "All popped!";
			}
			else {
				screenElements = &(ModeStack.top()->screenElements);
			}
			break;
		case ModeAction::RemoveAll:
			while (!ModeStack.empty()) {
				ModeStack.pop();
				std::cout << "Popped !";
			}
			std::cout << "All popped!";
			break;
		default:
			break;
		}
	}
	// Safely Kill Render Thread
	isRunning = false;
	RenderThread.join();
	window.close();
}

