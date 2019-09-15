#pragma once
#include "Mode.hpp"

class GameMode : public Mode
{
public:
	GameMode(std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* sfVec) : screenElements{ sfVec } { }
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* screenElements;
};