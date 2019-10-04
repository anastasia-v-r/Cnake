#pragma once
#include "Mode.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>

class GameMode : public Mode
{
public:
	GameMode(std::mutex*, float);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:
	void processKeys(sf::Keyboard::Key, bool);
private:
	Player mPlayer;
	float gameSpeed;
};