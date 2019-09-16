#include "MenuMode.hpp"

MenuMode::MenuMode() : Mode("MenuMode.json") {

}

std::pair<ModeAction, ModeOption> MenuMode::Run(sf::Time time, sf::RenderWindow& window) {
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {

	}
	// Handle Logic
	if (true)
		return std::make_pair(ModeAction::None, ModeOption::None);
}