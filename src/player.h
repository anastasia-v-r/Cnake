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

class Player : public sf::Drawable
{
public:

private:
	int score;
	direction dir;
	std::vector<sf::RectangleShape> snakeBody;
public:
	direction getDir();

	sf::Vector2f getSize();

	int getScore();

	void setColor(sf::Color, sf::Color);

	void setPosition(int, int);

	void setDir(sf::Keyboard::Key);

	void move();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Player(sf::Color headColor, sf::Color bodyColor, int screenWidth, int screenHeight)
		: score(0)
		, dir(STOP)
		, snakeBody(4, sf::RectangleShape(sf::Vector2f(50.0f, 50.0f)))
	{
		setColor(headColor, bodyColor);
		setPosition(screenWidth, screenHeight);
	}
	~Player()
	{
	}
};
