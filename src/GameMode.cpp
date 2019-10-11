#include "GameMode.hpp"
#include "Player.hpp"
#include <thread>
#include <chrono>
#include <iostream>

GameMode::GameMode(std::mutex* mutex, float speed)
	: Mode("GameMode.json", mutex, ModeOption::Game)
	, mPlayer(objectTextures, mutex)
	, gameSpeed{ speed } {
	eatSound.loadFromFile("assets/audio/eat.wav");
	eat.setBuffer(eatSound);
	eat.setVolume(50);
	dieSound.loadFromFile("assets/audio/die.wav");
	die.setBuffer(dieSound);
	eat.setVolume(50);
	font.loadFromFile("assets/fonts/bauh.ttf");
	score.setFont(font);
	score.setCharacterSize(30);
	score.setString("Score : 0");
	score.setPosition(1920 - (score.getLocalBounds().width + (score.getCharacterSize() * 2)), 0);
	screenObjects.emplace_back(&score);
	screenObjects.emplace_back(&mPlayer);
	sf::RectangleShape food(sf::Vector2f(50, 50));
	food.setPosition(510, 490);
	Mode::pushObject("food", food, "fruit");
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
		if (mPlayer.safeCheck(screenObjectsMap["food"], score, eat, die)) {
			return std::make_pair(ModeAction::Add, ModeOption::Lose);
		}
		auto [x, y] = mPlayer.getHeadPos();
		std::cout << "[" << x << "," << y << "]" << std::endl;
		timeBank -= (sf::seconds)(gameSpeed);
	} else {
		timeBank += time;
	}
	// In case of no state changes
	return std::make_pair(ModeAction::None, ModeOption::None);
}
