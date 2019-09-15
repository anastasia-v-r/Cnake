#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class GameMode : public Mode
{
public:
	GameMode(std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* sfVec);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:
	void GameMode::processKeys(sf::Keyboard::Key, bool);
private:
	std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* screenElements;
};