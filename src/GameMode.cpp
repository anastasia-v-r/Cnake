#include "GameMode.hpp"

std::pair<ModeAction, ModeOption> GameMode::Run(sf::Time time, sf::RenderWindow& window) {
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {

	}
	// Handle Logic
	if (true)
		return std::make_pair(ModeAction::None, ModeOption::None);
}