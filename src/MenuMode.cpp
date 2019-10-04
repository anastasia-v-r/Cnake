#include "MenuMode.hpp"
#include <iostream>

MenuMode::MenuMode(std::mutex* mutex) : Mode("MenuMode.json", mutex, ModeOption::Menu) {

}

std::pair<ModeAction, ModeOption> MenuMode::Run(sf::Time time, sf::RenderWindow& window) {
	float speed = 500.0f;
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		case sf::Event::MouseButtonPressed: {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			std::cout << "Mouse Position [" << mousePosF.x << ", " << mousePosF.y << "]" << std::endl;
			if (screenObjectsMap["playButton"].getGlobalBounds().contains(mousePosF)) {
				return std::make_pair(ModeAction::Add, ModeOption::Game);
			} else if (screenObjectsMap["settingsButton"].getGlobalBounds().contains(mousePosF)) {
				return std::make_pair(ModeAction::Add, ModeOption::Settings);
			} else if (screenObjectsMap["exitButton"].getGlobalBounds().contains(mousePosF)) {
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
			} else {
				std::cout << "You clicked on nothing!" << std::endl;
			}
			}
			break;
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
				break;
			default:
				std::cout << "Key [" << evnt.key.code << "] is not handled by State [MenuMode]" << std::endl;
				break;
			}
			break;
		case sf::Event::Closed:
			return std::make_pair(ModeAction::DropTo, ModeOption::None);
			break;
		default:
			break;
		}
	}
	// Update Game Logic

	// In case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
