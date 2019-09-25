#include "GameMode.hpp"
#include "Player.hpp"
#include <thread>
#include <chrono>
#include <iostream>

GameMode::GameMode(std::mutex* mutex)
	: Mode("GameMode.json", mutex, ModeOption::Game)
	, mPlayer(objectTextures) {
	screenObjects.emplace_back(&mPlayer);
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
				for (auto& key : mKeys) {
					key.second = false;
					std::cout << key.first << " is now false" << std::endl;
				}
				return std::make_pair(ModeAction::Add, ModeOption::Paused);
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
			return std::make_pair(ModeAction::DropTo, ModeOption::None);
			break;
		}
	}
	// Update Game Logic
	if (timeBank.asSeconds() > .02) {

	} else {
		timeBank += time;
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
