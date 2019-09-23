// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <thread>
#include <mutex>
#include <atomic>
#include <Player.hpp>
#include <ModeList.hpp>
#include <RuntimeStats.hpp>
// Entry Point
int main() {
	static std::mutex mu;
	// Setup Window
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	window.setActive(false);
	// Prepare Stack
	std::stack<std::unique_ptr<Mode>> ModeStack;
	ModeStack.push(std::make_unique<IntroMode>(&mu));
	// Variable for killing thread safely
	std::atomic<bool> isRunning = true;
	std::atomic<bool> showStats = true;
	std::atomic<bool> isPaused = false;
	std::atomic<bool> isWaiting = false;
	// Create Rendering Thread
	// TODO: Fix wierd rendering error that occurs when repushing old states
	std::thread RenderThread([&window, &ModeStack, &isRunning, &showStats, &isPaused, &isWaiting] {
		// Window Settings
		window.setActive(true);
		//window.setFramerateLimit(60);
		// Setup Stats
		RuntimeStats stats;
		// Render Loop
		while (isRunning) {
			if (!isPaused) {
				// Rendering
				window.clear();
				mu.lock();
				for (const auto& element : ModeStack.top()->screenObjects) {
					window.draw(*element);
				}
				if (showStats) {
					stats.draw(window);
				}
				window.display();
				mu.unlock();
				stats.update();
			} else {
				window.setActive(false);
				isWaiting = true;
				while (true) {
					if (!isPaused) {
						window.setActive(true);
						break;
					}
				}
			}
		}
		std::cout << "Yeh" << std::endl;
	});
	// Begin Game
	sf::Clock GameClock;
	while (!ModeStack.empty()) {
		sf::Time timePassed = GameClock.restart();
		auto result = ModeStack.top()->Run(timePassed, window);
		if (result.first != ModeAction::None) {
			sf::Event evnt;
			while (window.pollEvent(evnt));
			switch (result.first)
			{
			case ModeAction::Add:
				switch (result.second)
				{
				case ModeOption::Intro:
					ModeStack.push(std::make_unique<IntroMode>(&mu));
					break;
				case ModeOption::Menu:
					ModeStack.push(std::make_unique<MenuMode>(&mu));
					break;
				case ModeOption::Settings:
					ModeStack.push(std::make_unique<SettingsMode>(&mu));
					break;
				case ModeOption::Game:
					ModeStack.push(std::make_unique<GameMode>(&mu));
					break;
				case ModeOption::Paused:
					isPaused = true;
					while (!isWaiting) {
					}
					window.setActive(true);
					ModeStack.push(std::make_unique<PausedMode>(&mu, window.capture()));
					window.setActive(false);
					isPaused = false;
					break;
				}
				break;
			case ModeAction::DropTo:
				// Safely Kill Render Thread
				if (result.second == ModeOption::None) {
					isRunning = false;
					RenderThread.join();
				}
				mu.lock();
				while (!(ModeStack.empty()) && (ModeStack.top()->type() != result.second)) {
					ModeStack.pop();
				}
				if (ModeStack.empty()) {
					window.close();
				}
				mu.unlock();
				isRunning = true;
				break;
			default:
				break;
			}
		}
	}
	std::cout << "All done" << std::endl;
	//std::cin.ignore(1);
}

