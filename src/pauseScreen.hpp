#include "screen.hpp"
#include <SFML/Graphics.hpp>

class PauseScreen : public Screen
{
public:
	PauseScreen(int sWidth, int sHeight) : Screen() 
	{
		sf::RectangleShape fade(sf::Vector2f(sWidth, sHeight));
		fade.setOrigin(sWidth / 2, sHeight / 2);
		fade.setPosition(sWidth / 2, sHeight / 2);
		fade.setFillColor(sf::Color(0, 0, 0, 255 / 2));
	}
};