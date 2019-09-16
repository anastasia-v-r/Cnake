#include "IntroMode.hpp"

IntroMode::IntroMode() : Mode("IntroMode.json") {
	auto mode = sf::VideoMode::getDesktopMode();
	
}

std::pair<ModeAction, ModeOption> IntroMode::Run(sf::Time time, sf::RenderWindow& window) {
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		case sf::Event::Closed:
			return std::make_pair(ModeAction::Remove, ModeOption::None);
			break;
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::Remove, ModeOption::None);
				break;
			case sf::Keyboard::BackSpace:
				return std::make_pair(ModeAction::Remove, ModeOption::None);
				break;
			case sf::Keyboard::RSystem: // Block windows key
				break;
			case sf::Keyboard::LSystem: // Block windows key
				break;
			default:
				return std::make_pair(ModeAction::Add, ModeOption::Game);
				break;
			}
			break;
		}
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}