#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player : public sf::Drawable
{
public:
	Player(const std::map<std::string, sf::Texture>&);
	~Player();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::RectangleShape> snakeBody;
};
