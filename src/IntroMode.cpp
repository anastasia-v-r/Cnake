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
			case sf::Keyboard::Escape:
			case sf::Keyboard::BackSpace:
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
				break;
			case sf::Keyboard::RSystem: // Block windows key
			case sf::Keyboard::LSystem: 
				break;
			default:
				return std::make_pair(ModeAction::Add, ModeOption::Menu);
				break;
			}
			break;
		}
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}