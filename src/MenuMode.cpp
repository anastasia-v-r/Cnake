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
		case sf::Event::MouseButtonPressed:
			break;
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
				break;
			case sf::Keyboard::BackSpace:
				return std::make_pair(ModeAction::DropTo, ModeOption::Intro);
				break;
			case sf::Keyboard::Enter:
				return std::make_pair(ModeAction::Add, ModeOption::Game);
				break;
			default:
				std::cout << "Key [" << evnt.key.code << "] is not handeled by State [MenuMode]" << std::endl;
				break;
			}
			break;
		case sf::Event::KeyReleased:
			break;
		case sf::Event::Closed:
			return std::make_pair(ModeAction::DropTo, ModeOption::None);
			break;
		}
	}
	// Update Game Logic

	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
