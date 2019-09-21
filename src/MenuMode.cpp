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
			std::cout << "Mouse Pos [" << mousePosF.x << ", " << mousePosF.y << "]" << std::endl;
			/*if ((mousePosF.x > 770.0f) && (mousePosF.x < 1250.0f) && (mousePosF.y > 440.0f) && (mousePosF.y < 630.0f)) {
				return std::make_pair(ModeAction::Add, ModeOption::Game);
			} else if ((mousePosF.x > 770.0f) && (mousePosF.x < 1250.0f) && (mousePosF.y > 650.0f) && (mousePosF.y < 840.0f)) {
				return std::make_pair(ModeAction::Add, ModeOption::Settings);
			} else if ((mousePosF.x > 770.0f) && (mousePosF.x < 1250.0f) && (mousePosF.y > 860.0f) && (mousePosF.y < 1050.0f)) {
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
			} else {
				std::cout << "You clicked on nothing!" << std::endl;
			}*/
			std::cout << "[" << screenObjectsMap["playButton"].getPosition().x << ", " << screenObjectsMap["playButton"].getPosition().y << "]" << std::endl;
			std::cout << "[" << screenObjectsMap["playButton"].getPosition().x << ", " << screenObjectsMap["playButton"].getPosition().y << "]" << std::endl;
			if (screenObjectsMap["playButton"].getGlobalBounds().contains(mousePosF)) {
				//return std::make_pair(ModeAction::Add, ModeOption::Game);
				std::cout << "Play Button" << std::endl;
			} else if (screenObjectsMap["settingsButton"].getGlobalBounds().contains(mousePosF)) {
				//return std::make_pair(ModeAction::Add, ModeOption::Settings);
				std::cout << "Settings Button" << std::endl;
			} else if (screenObjectsMap["exitButton"].getGlobalBounds().contains(mousePosF)) {
				//return std::make_pair(ModeAction::DropTo, ModeOption::None);
				std::cout << "Exit Button" << std::endl;
			}
			else {
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
				std::cout << "Key [" << evnt.key.code << "] is not handeled by State [MenuMode]" << std::endl;
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

	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
