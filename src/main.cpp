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
	// Setup Window
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	// Prepare Stack
	std::stack<std::unique_ptr<Mode>> ModeStack;
	ModeStack.push(std::make_unique<IntroMode>());
	// Begin Game
	sf::Clock GameClock;
	while (!ModeStack.empty()) {
		sf::Time timePassed = GameClock.restart();
		auto result = ModeStack.top()->Run(timePassed, window);
		if (result.first != ModeAction::None) {
			switch (result.first)
			{
			case ModeAction::Add:
				switch (result.second)
				{
				case ModeOption::Intro:
					ModeStack.push(std::make_unique<IntroMode>());
					break;
				case ModeOption::Menu:
					ModeStack.push(std::make_unique<MenuMode>());
					break;
				case ModeOption::Settings:
					ModeStack.push(std::make_unique<SettingsMode>());
					break;
				case ModeOption::Game:
					ModeStack.push(std::make_unique<GameMode>());
					break;
				case ModeOption::Paused:
					ModeStack.push(std::make_unique<PausedMode>());
					break;
				}
				break;
			case ModeAction::DropTo:
				while (!(ModeStack.empty()) && (ModeStack.top()->type() != result.second)) {
					ModeStack.pop();
				}
				if (ModeStack.empty()) {
					window.close();
				}
				break;
			default:
				break;
			}
		}
	}
	std::cout << "All done" << std::endl;
	//std::cin.ignore(1);
}

