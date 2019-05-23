#include "screen.hpp"
#include "SFML/Graphics.hpp"

class StartScreen : public Screen
{
private:
	sf::RectangleShape* fade{ new sf::RectangleShape };
public:
	StartScreen(int sWidth, int sHeight) : Screen({fade})
	{
		fade->setSize(sf::Vector2f(sWidth, sHeight));
		fade->setOrigin(sWidth / 2, sHeight / 2);
		fade->setPosition(sWidth / 2, sHeight / 2);
		fade->setFillColor(sf::Color(0, 0, 0, (255 / 4) * 3));
	}
};

//sf::RectangleShape fade(sf::Vector2f(sWidth, sHeight));
//fade.setOrigin(sWidth / 2, sHeight / 2);
//fade.setPosition(sWidth / 2, sHeight / 2);
//fade.setFillColor(sf::Color(0, 0, 0, (255 / 4) * 3));