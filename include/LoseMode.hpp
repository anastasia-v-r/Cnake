#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class LoseMode : public Mode
{
public:
	LoseMode(std::mutex*, sf::Image);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	sf::Image screenShot;
	sf::Texture gameScreen;
};