#include "GameMode.hpp"
#include "Player.hpp"
#include <thread>
#include <chrono>
#include <iostream>

GameMode::GameMode(std::mutex* mutex, float speed)
	: Mode("GameMode.json", mutex, ModeOption::Game)
	, mPlayer(objectTextures, mutex)
	, gameSpeed{ speed } {
	screenObjects.emplace_back(&mPlayer);
	sf::RectangleShape food(sf::Vector2f(50, 50));
	food.setPosition(500, 500);
	Mode::pushObject("food", food, "Blue");
}

std::pair<ModeAction, ModeOption> GameMode::Run(sf::Time time, sf::RenderWindow& window) {
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
	if (timeBank.asSeconds() > gameSpeed) {
		mPlayer.movePlayer();
		if (mPlayer.safeCheck(screenObjectsMap["food"])) {
			return std::make_pair(ModeAction::Add, ModeOption::Lose);
		}
		timeBank -= (sf::seconds)(gameSpeed);
	} else {
		timeBank += time;
	}
	// Im case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
