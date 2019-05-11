#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
// Data
private:
	int score; // Points
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
		, snake(3, sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)))
	{
	}
	~Player()
	{
	}
};
