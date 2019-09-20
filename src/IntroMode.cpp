#include "IntroMode.hpp"

IntroMode::IntroMode(std::mutex* mutex) : Mode("IntroMode.json", mutex, ModeOption::Intro) {
	auto mode = sf::VideoMode::getDesktopMode();
	
}

std::pair<ModeAction, ModeOption> IntroMode::Run(sf::Time time, sf::RenderWindow& window) {
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		case sf::Event::Closed:
			return std::make_pair(ModeAction::DropTo, ModeOption::None);
			break;
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::RSystem: // Block windows and other system keys
			case sf::Keyboard::LSystem: 
			case sf::Keyboard::LAlt:
			case sf::Keyboard::RAlt:
			case sf::Keyboard::LControl:
			case sf::Keyboard::RControl:
				break;
			default:
				return std::make_pair(ModeAction::Add, ModeOption::Menu);
				break;
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (window.hasFocus()) {
				return std::make_pair(ModeAction::Add, ModeOption::Menu);
			}
		}
	}
	// Handle Passive Logic

	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}