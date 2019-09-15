#include "MenuMode.hpp"

MenuMode::MenuMode(std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* sfVec)
	: screenElements{ sfVec } {
	for (const auto& element : *screenElements) {
		delete element.first;
		delete element.second;
	}
	for (int i = 0; i < screenElements->size(); i++) {
		screenElements->pop_back();
	}
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