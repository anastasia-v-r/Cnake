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
#include <Windows.h>
// Entry Point
int main() {
	static std::mutex mu;
	// Setup Window
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	window.setActive(false);
	window.setActive(true);
	window.setFramerateLimit(60);
	// Prepare Stack
	std::stack<std::unique_ptr<Mode>> ModeStack;
	ModeStack.push(std::make_unique<IntroMode>(&mu));
	// Variable for killing thread safely
	bool isRunning = true;
	// Create Rendering Thread
	// TODO: Fix wierd rendering error that occurs when repushing old states
	/*std::thread RenderThread([&window, &ModeStack, &isRunning] {
		// Window Settings
		window.setActive(true);
		window.setFramerateLimit(60);
		// Setup Stats
		RuntimeStats stats;
		// Render Loop
		while (isRunning) {
			// Rendering
			window.clear();
			mu.lock();
				for (const auto& object : ModeStack.top()->screenObjects) {
					window.draw(object);
				}
			stats.draw(window);
			window.display();
			stats.update();
			mu.unlock();
		}
	});*/
	// Setup Stats
	RuntimeStats stats;
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
				ModeStack.push(std::make_unique<IntroMode>(&mu));
				break;
			case ModeOption::Menu:
				ModeStack.push(std::make_unique<MenuMode>(&mu));
				break;
			case ModeOption::Game:
				ModeStack.push(std::make_unique<GameMode>(&mu));
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
		// render loop
		window.clear();
		for (const auto& object : ModeStack.top()->screenObjects) {
			window.draw(object);
		}
		stats.draw(window);
		window.display();
		stats.update();
	}
	// Safely Kill Render Thread
	isRunning = false;
	//RenderThread.join();
	window.close();
}

