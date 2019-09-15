#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class IntroMode : public Mode
{
public:
	IntroMode(std::vector<sf::RectangleShape>* sfVec) : screenElements{ sfVec } { }
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	std::vector<sf::RectangleShape>* screenElements;
};