#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class IntroMode : public Mode
{
public:
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:

};