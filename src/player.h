#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum direction {
	STOP = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

class Player
{
// Data
private:
	int score; // Points
	direction dir;
	std::vector<sf::RectangleShape> snake; // Body
// Methods
public:
	
	void setColor(sf::Color, sf::Color);

	void setPosition();

	void move(sf::Keyboard::Key);

	void drawSnake(sf::RenderWindow);

	sf::RectangleShape* access();

	Player() 
		: score(0)
		, dir(STOP)
		, snake(3, sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)))
	{
	}
	~Player()
	{
	}
};
