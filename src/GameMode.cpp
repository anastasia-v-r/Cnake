#include "GameMode.hpp"
#include <thread>
#include <chrono>

GameMode::GameMode() : Mode("GameMode.json") {
	mKeys = {
		{"Up", false},
		{"Right", false},
		{"Down", false},
		{"Left", false}
	};
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
			case sf::Keyboard::Space: {
				auto mode = sf::VideoMode::getDesktopMode();
				sf::RectangleShape player{sf::RectangleShape(sf::Vector2f(100.0f, 100.0f))};
				player.setPosition(sf::Vector2f((float)mode.width / 2.0f, (float)mode.height / 2.0f));
				if (!screenObjectsMap.count("Player"))
					pushObject("Player", player, "snakebody");
				break;
			}
			case sf::Keyboard::Enter:
				if (screenObjectsMap.count("Player"))
					popObject("Player");
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
	if (screenObjectsMap.count("Player")) {
		if (mKeys["Up"])
			screenObjectsMap["Player"]->move(0.0f, -speed * time.asSeconds());
		if (mKeys["Right"])
			screenObjectsMap["Player"]->move(speed * time.asSeconds(), 0.0f);
		if (mKeys["Down"])
			screenObjectsMap["Player"]->move(0.0f, speed * time.asSeconds());
		if (mKeys["Left"])
			screenObjectsMap["Player"]->move(-speed * time.asSeconds(), 0.0f);
	}
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