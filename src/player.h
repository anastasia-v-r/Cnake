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
	// Getters
	direction getDir();

	sf::Vector2f getSize();

	int getScore();
	// Setters
	void setColor(sf::Color, sf::Color);

	void setPosition(int, int);

	void setDir(sf::Keyboard::Key);

	void move();

	void drawSnake(sf::RenderWindow&);

	Player() 
		: score(0)
		, dir(STOP)
		, snake(4, sf::RectangleShape(sf::Vector2f(50.0f, 50.0f)))
	{
	}
	~Player()
	{
	}
};
