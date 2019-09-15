#pragma once
#include "Mode.hpp"

class MenuMode : public Mode
{
public:
	MenuMode(std::vector<sf::RectangleShape>* sfVec) : screenElements{ sfVec } { }
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	std::vector<sf::RectangleShape>* screenElements;
};