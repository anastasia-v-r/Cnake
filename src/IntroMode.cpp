#include "IntroMode.hpp"

IntroMode::IntroMode() {
	auto mode = sf::VideoMode::getDesktopMode();
	sf::RectangleShape* splash{ new sf::RectangleShape(sf::Vector2f((float)mode.width, (float)mode.height)) };
	sf::Texture* splashTexture{ new sf::Texture };
	splashTexture->loadFromFile("assets/textures/splash.png");
	splash->setTexture(splashTexture);
	screenElements.push_back(std::make_pair(splash, splashTexture));
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
			if (evnt.key.code == sf::Keyboard::Key::Escape) {
				return std::make_pair(ModeAction::Remove, ModeOption::None);
			} else {
				// TODO: Game->Menu once proof of concept is finished
				return std::make_pair(ModeAction::Add, ModeOption::Game);
			}
			break;
		}
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}