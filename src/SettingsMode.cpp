#include "SettingsMode.hpp"
#include "Settings.hpp"
#include <iostream>

SettingsMode::SettingsMode(std::mutex* mutex, Settings* settings) : settings{ settings }, Mode("SettingsMode.json", mutex, ModeOption::Intro) {
	fps = settings->getFpsLock();
	speed = settings->getGameSpeed();
	auto mode = sf::VideoMode::getDesktopMode();
}

std::pair<ModeAction, ModeOption> SettingsMode::Run(sf::Time time, sf::RenderWindow& window) {
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
				return std::make_pair(ModeAction::DropTo, ModeOption::Menu);
				break;
			}
			break;
		case sf::Event::MouseButtonPressed: {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (screenObjectsMap["fps60"].getGlobalBounds().contains(mousePosF))
				fps = true;
			else if (screenObjectsMap["fpsUnlimited"].getGlobalBounds().contains(mousePosF))
				fps = false;
			else if (screenObjectsMap["speedSlow"].getGlobalBounds().contains(mousePosF))
				speed = .20f;
			else if (screenObjectsMap["speedMed"].getGlobalBounds().contains(mousePosF))
				speed = .10f;
			else if (screenObjectsMap["speedFast"].getGlobalBounds().contains(mousePosF))
				speed = .05f;
			else if (screenObjectsMap["SaveButton"].getGlobalBounds().contains(mousePosF)) {
				settings->setFpsLock(fps);
				settings->setGameSpeed(speed);
				return std::make_pair(ModeAction::DropTo, ModeOption::One);
			}
			else if (screenObjectsMap["ExitButton"].getGlobalBounds().contains(mousePosF))
				return std::make_pair(ModeAction::DropTo, ModeOption::One);
			}
			break;
		default:
			break;
		}
	}
	// Handle Passive Logic
	if (timeBank.asSeconds() > .01) {

	} else {
		timeBank += time;
	}
	// In case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}