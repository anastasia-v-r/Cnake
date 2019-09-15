#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class MenuMode : public Mode
{
public:
	MenuMode(std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* sfVec);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	std::vector<std::pair<sf::RectangleShape*, sf::Texture*>>* screenElements;
};