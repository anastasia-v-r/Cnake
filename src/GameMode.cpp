#include "GameMode.hpp"
#include "Player.hpp"
#include <thread>
#include <chrono>
#include <iostream>

GameMode::GameMode(std::mutex* mutex)
	: Mode("GameMode.json", mutex, ModeOption::Game)
	, mPlayer(objectTextures) {
	screenObjects.emplace_back(&mPlayer);
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
				return std::make_pair(ModeAction::Add, ModeOption::Paused);
				break;
			default:
				mPlayer.processKeys(evnt.key.code);
				break;
			}
			break;
		case sf::Event::Closed:
			return std::make_pair(ModeAction::DropTo, ModeOption::None);
			break;
		}
	}
	// Update Game Logic
	if (timeBank.asSeconds() > .20) {
		mPlayer.movePlayer();
		timeBank -= (sf::seconds)(0.20f);
	} else {
		timeBank += time;
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
