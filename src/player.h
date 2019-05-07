#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class player
{
// Data
private:
	int score;
	std::vector<sf::RectangleShape> snake;
// Methods
public:

	player();
	~player();
};

