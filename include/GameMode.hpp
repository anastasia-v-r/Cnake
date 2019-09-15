#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class GameMode : public Mode
{
public:
	GameMode();
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:
	void GameMode::processKeys(sf::Keyboard::Key, bool);
private:
	std::map<std::string, bool> mKeys;
};