#include "PausedMode.hpp"

PausedMode::PausedMode() : Mode("PausedMode.json", ModeOption::Intro) {
	auto mode = sf::VideoMode::getDesktopMode();
}

std::pair<ModeAction, ModeOption> PausedMode::Run(sf::Time time, sf::RenderWindow& window) {
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
			case sf::Keyboard::BackSpace:
				return std::make_pair(ModeAction::DropTo, ModeOption::Game);
				break;
			}
			break;
		default:
			break;
		}
	}
	// Handle Passive Logic
	if (timeBank.asSeconds() > .01) {

	}
	else {
		timeBank += time;
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}