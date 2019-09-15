#include "GameMode.hpp"
#include <thread>
#include <chrono>

std::map<std::string, bool> mKeys = {
		{"Up", false},
		{"Right", false},
		{"Down", false},
		{"Left", false}
};

GameMode::GameMode(std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* sfVec)
	: screenElements{ sfVec } {
	for (const auto& element : *screenElements) {
		delete element.first;
		delete element.second;
	}
	for (int i = 0; i < screenElements->size(); i++) {
		screenElements->pop_back();
	}
	auto mode = sf::VideoMode::getDesktopMode();
	sf::RectangleShape* playField{ new sf::RectangleShape(sf::Vector2f((float)mode.width, (float)mode.height)) };
	sf::RectangleShape* player{ new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)) };
	sf::Texture* playFieldTexture{ new sf::Texture };
	sf::Texture* playerTexutre{ new sf::Texture };
	playFieldTexture->loadFromFile("assets/textures/playfield.png");
	playerTexutre->loadFromFile("assets/textures/snakebody.png");
	playField->setTexture(playFieldTexture);
	player->setTexture(playerTexutre);
	player->setPosition(sf::Vector2f((float)mode.width / 2.0f, (float)mode.height / 2.0f));
	screenElements->push_back(std::make_pair(playField, playFieldTexture));
	screenElements->push_back(std::make_pair(player, playerTexutre));
}

std::pair<ModeAction, ModeOption> GameMode::Run(sf::Time time, sf::RenderWindow& window) {
	float speed = 500.0f;
	// Handle Input
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Escape:
				return std::make_pair(ModeAction::RemoveAll, ModeOption::None);
				break;
			case sf::Keyboard::BackSpace:
				return std::make_pair(ModeAction::Remove, ModeOption::None);
				break;
			default:
				processKeys(evnt.key.code, true);
				break;
			}
			break;
		case sf::Event::KeyReleased:
			processKeys(evnt.key.code, false);
			break;
		case sf::Event::Closed:
			return std::make_pair(ModeAction::RemoveAll, ModeOption::None);
			break;
		}
	}
	// Update Game Logic
	if (mKeys["Up"])
		(*screenElements)[1].first->move(0.0f, -speed * time.asSeconds());
	if (mKeys["Right"])
		(*screenElements)[1].first->move(speed * time.asSeconds(), 0.0f);
	if (mKeys["Down"])
		(*screenElements)[1].first->move(0.0f, speed * time.asSeconds());
	if (mKeys["Left"])
		(*screenElements)[1].first->move(-speed * time.asSeconds(), 0.0f);
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}

void GameMode::processKeys(sf::Keyboard::Key key, bool pressed) {
	switch (key)
	{
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		mKeys["Up"] = pressed;
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		mKeys["Right"] = pressed;
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		mKeys["Down"] = pressed;
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		mKeys["Left"] = pressed;
		break;
	}
}