#include "IntroMode.hpp"
#include <iostream>

IntroMode::IntroMode(std::mutex* mutex) : fading{ fadeStage::In } , Mode("IntroMode.json", mutex, ModeOption::Intro) {
	auto mode = sf::VideoMode::getDesktopMode();
	screenObjectsMap["fadeCover"]->setFillColor(sf::Color(255, 255, 255, 255));
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
			case sf::Keyboard::Enter:
				return std::make_pair(ModeAction::DropTo, ModeOption::None);
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
	if (timeBank.asSeconds() > .01) {
		switch (fading)
		{
		case fadeStage::In:
			if (screenObjectsMap["fadeCover"]->getFillColor().a > 0) {
				sf::Color temp = screenObjectsMap["fadeCover"]->getFillColor();
				temp.a--;
				screenObjectsMap["fadeCover"]->setFillColor(temp);
				std::cout << "Fading ..." << std::endl;
				timeBank = (sf::seconds)(timeBank.asSeconds() - .01);
			} else {
				fading = fadeStage::Out;
			}
			break;
		case fadeStage::Out:
			if (screenObjectsMap["fadeCover"]->getFillColor().a < 255) {
				sf::Color temp = screenObjectsMap["fadeCover"]->getFillColor();
				temp.a++;
				screenObjectsMap["fadeCover"]->setFillColor(temp);
				std::cout << "Fading ..." << std::endl;
				timeBank = (sf::seconds)(timeBank.asSeconds() - .01);
			}
			else {
				fading = fadeStage::Over;
			}
			break;
		case fadeStage::Over:
			return std::make_pair(ModeAction::Add, ModeOption::Menu);
			break;
		}
	} else {
		timeBank += time;
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}