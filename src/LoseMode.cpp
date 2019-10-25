#include "LoseMode.hpp"
#include <iostream>

LoseMode::LoseMode(std::mutex* mutex, sf::Image ss) : screenShot{ ss }, Mode("LoseMode.json", mutex, ModeOption::Paused) {
	auto [x, y, z] = sf::VideoMode::getDesktopMode();
	float diff = 1920 - x;
	float diffP = 1920 / diff;
	x = (float)x - ((float)x * diffP);
	y = (float)y - ((float)y * diffP);
	gameScreen.loadFromImage(screenShot, sf::IntRect(0, 0, x, y));
	screenObjectsMap["game"].setTexture(&gameScreen);
}

std::pair<ModeAction, ModeOption> LoseMode::Run(sf::Time time, sf::RenderWindow& window) {
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
			case sf::Keyboard::Enter:
				return std::make_pair(ModeAction::DropTo, ModeOption::Menu);
			default:
				break;
			}
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