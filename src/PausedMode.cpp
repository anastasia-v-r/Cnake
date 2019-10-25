#include "PausedMode.hpp"
#include <iostream>

PausedMode::PausedMode(std::mutex* mutex, sf::Image ss) : screenShot{ ss }, Mode("PausedMode.json", mutex, ModeOption::Paused) {
	auto [x, y, z] = sf::VideoMode::getDesktopMode();
	float diffp = (std::abs(1920.0f - x) / ((1920.0f + x) / 2.0f));
	std::cout << "DIFF[" << diffp << "]" << std::endl;
	std::cout << "x[" << x << "]y[" << y << "]" << std::endl;
	//x -= (float)x * diffp;
	x -= 160;
	//y -= (float)y * diffp;
	y -= 90;
	std::cout << "x[" << x << "]y[" << y << "]" << std::endl;
	gameScreen.loadFromImage(screenShot, sf::IntRect(0, 0, x , y));
	screenObjectsMap["game"].setTexture(&gameScreen);
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
		case sf::Event::MouseButtonPressed: {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			mousePosF *= ratio;
			if (screenObjectsMap["ResumeButton"].getGlobalBounds().contains(mousePosF)) {
				return std::make_pair(ModeAction::DropTo, ModeOption::One);
			} else if (screenObjectsMap["ExitButton"].getGlobalBounds().contains(mousePosF)) {
				return std::make_pair(ModeAction::DropTo, ModeOption::Menu);
			}
			}
			break;
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::DropTo, ModeOption::One);
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