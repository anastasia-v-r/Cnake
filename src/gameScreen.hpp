#include "screen.hpp"
#include <SFML/Graphics.hpp>

class GameScreen : public Screen
{
public:
	GameScreen(int sWidth, int sHeight, int snakeSize) : Screen()
	{
		sf::RectangleShape background(sf::Vector2f(sWidth, sHeight));
		background.setFillColor(sf::Color(255, 255, 255, 50));
		background.setOrigin(background.getSize().x / 2, background.getSize().y / 2);
		background.setPosition(sWidth / 2, sHeight / 2);
		sf::RectangleShape playBox(sf::Vector2f(sWidth - snakeSize, sHeight - snakeSize));
		playBox.setFillColor(sf::Color::Transparent);
		playBox.setOutlineThickness(10.0f);
		playBox.setOutlineColor(sf::Color(255, 255, 255, 130));
		playBox.setOrigin(sWidth / 2, sHeight / 2);
		playBox.setPosition(sWidth / 2, sHeight / 2);
	};
};
