#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class IntroMode : public Mode
{
public:
	IntroMode(std::mutex* mutex);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	
};