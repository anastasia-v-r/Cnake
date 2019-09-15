#pragma once
#include "Mode.hpp"

class GameMode : public Mode
{
public:
	GameMode(std::vector<sf::RectangleShape>* sfVec) : screenElements{ sfVec } { }
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	std::vector<sf::RectangleShape>* screenElements;
};