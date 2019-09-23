#include "PausedMode.hpp"

PausedMode::PausedMode(std::mutex* mutex, sf::Image ss) : screenShot{ ss }, Mode("PausedMode.json", mutex, ModeOption::Intro) {
	auto mode = sf::VideoMode::getDesktopMode();
	gameScreen.loadFromImage(screenShot);
	screenObjectsMap["background"].setTexture(&gameScreen);
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
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::DropTo, ModeOption::Menu);
				break;
			case sf::Keyboard::Enter:
				return std::make_pair(ModeAction::Add, ModeOption::Settings);
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